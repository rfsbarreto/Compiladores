#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef enum {MNG_PROG,MNG_DEC,MNG_DECVAR,MNG_LISTNOM,MNG_TIPO,MNG_TIPBASE,MNG_DECFUNC,MNG_PARS, MNG_IF, MNG_WHILE,MNG_ATRIB, MNG_OP, MNG_NAO, MNG_TIPEXP, MNG_RETURN, MNG_OPNEG,
MNG_PAR,MNG_BLOCO,MNG_DECVARS,MNG_CMD,MNG_CMDS,MNG_PTELSE,MNG_VAR,MNG_EXP,MNG_CHMET,MNG_LSTEXP} tipo_no;

typedef enum mng_tipbase { 
	TIPO_INT,TIPO_CHAR,TIPO_STRING,TIPO_FLOAT,TIPO_VAZIO
	}
mng_tipbase ; //tipobase

typedef enum mng_operadores { 
	OP_NAO, OP_SOMA, OP_SUB, OP_MULT, OP_DIV, OP_IGUAL, OP_MENORIG, OP_MAIORIG, OP_MENORQ, OP_MAIORQ, OP_OU, OP_E
	}
mng_operadores ; //operadores

typedef struct mng_id{
    char* name;
} mng_id;


typedef struct mng_numint{
     int valor;
} mng_numint;

typedef struct mng_numfloat{
    float valor;
} mng_numfloat;

typedef struct mng_string{
    char* valor;
} mng_string;


/*
typedef struct mng_exp { 
    char* name;
	//DEC(exp);
} mng_exp;
*/
typedef struct mng_chmet{
	struct mng_id id;
	struct mng_listexp* listexp;
}mng_chmet;
/*
chamadaMetodo : ID APAR listaexp FPAR {}
;*/

typedef struct mng_nao{
	mng_operadores op;
	struct mng_exp* exp;//DEC(exp);
}mng_nao;

typedef struct mng_tipexp{
	struct mng_tip* tip;//	DEC(tip);
	struct mng_exp* exp;//DEC(exp);
}mng_tipexp;


typedef struct mng_exp{
	tipo_no tipoexp;
	mng_tipbase tipo;
	union{
		struct mng_tip *tip;
		struct mng_var* var;//DEC(var);
		struct mng_exp* exp;//DEC(exp);
		DEC(chmet);
		DEC(nao);
		struct mng_op* op;//DEC(op);
		DEC(tipexp);
		DEC(numint);
		DEC(numfloat);
		DEC(string);
};
}mng_exp;

typedef struct mng_listexp{
	DEC(exp);
	struct mng_listexp* listexp;
}mng_listexp;
/*
listaexp :  {}
			| exp {}
			| exp VIRG listaexp {}
;
*/

typedef struct mng_op{
	mng_exp exp1;
	mng_operadores op;
	mng_exp exp2; 
}mng_op;


/*
exp : NUMINT {}
	| NUMFLOAT {}
	| STRING {}
	| var{}
	| APAR exp FPAR{}
	| chamadaMetodo {}
    	| NEW tipo ACOL exp FCOL {}
	| SUB exp {}
	| exp SOMA exp {}
	| exp SUB exp {}
	| exp MULT exp {}
	| exp DIV exp  {}
	| exp IGUAL exp {}
	| exp MENORIG exp {}
	| exp MAIORIG exp  {}
	| exp MENORQ exp {}
	| exp MAIORQ exp {}
	| NAO exp {}
	| exp E exp {}
	| exp OU exp {}
;
*/






typedef struct mng_tip{
	//union {
	DEC(tipbase);
	//	struct mng_tip* tip;
	//};
}mng_tip;




/*
tipo : tipobase  { $$=$1; }
	| tipo ACOL FCOL {}
;
*/



typedef struct mng_var{
	DEC(id);
	mng_exp * exp;
} mng_var;
/*
	var : ID  {  }// $$.id=$1; }
	| var ACOL exp FCOL {}
;
*/




typedef struct { 
	DEC(id);
//	DEC(virg)
	//DEC(listnom);	
} mng_listnom2 ; //listanomes

typedef struct mng_listnom { 
	//union{
		DEC(id);
		struct mng_listnom* list;
		//mng_listnom2 listnom2;
		//struct mng_listnom3 listnom3;
	//};
} mng_listnom ; //listanomes
/*
listanomes : ID { }
	| ID VIRG listanomes  { }
	|  {}
;
*/


typedef struct mng_decvar{ 
    DEC(tip);
    DECP(listnom);
   // DEC(ptvirg)
} mng_decvar ;   // decvariavel
/*
decvariavel : tipo listanomes PTVIRG { $$=$1; }
;
*/


typedef struct mng_decvars{
	mng_decvar decvar;
	struct mng_decvars* decvars;

} mng_decvars;
/*
decvariaveis : decvariavel  decvariaveis
	|
;
*/



typedef struct mng_atrib{
	DEC(var);
	DEC(exp);
} mng_atrib;



typedef struct mng_ptelse{
	struct mng_cmd* cmd;
} mng_ptelse;

/*parteelse :           {$$ = NULL;}
	| ELSE comando {}
;

*/

typedef struct mng_decif { 
//    char* name;
	DEC(exp);
	struct mng_cmd* cmd;
	mng_ptelse* ptelse;
	
} mng_decif;

typedef struct mng_decwhile { 
//    char* name;
	DEC(exp);
	struct mng_cmd* cmd;
	
} mng_decwhile;


typedef struct mng_cmd{
	tipo_no tipocmd;
	union{
		DEC(decif);
		DEC(decwhile);
		DEC(atrib);
		struct mng_bloco* bloco;
		mng_exp * exp;
		DEC(chmet);
	//	struct mng_cmds2 cmds2;
	};
} mng_cmd;



typedef struct mng_cmds{
	mng_cmd cmd;
	struct mng_cmds* cmds;
} mng_cmds;
/*
comandos: comando comandos
	|
;
*/

typedef struct mng_bloco{ 
//	DEC(achave); //achave?
	mng_decvars* decvars;
	mng_cmds* cmds;
//	DEC(fchave);
} mng_bloco ; //bloco




/*
bloco : ACHAVE decvariaveis comandos FCHAVE ;
*/



typedef struct mng_par{
    DEC(tip);
    DEC(id);
} mng_par ; //parametro
/*
parametro : tipo ID;
*/



typedef struct mng_pars{
	struct mng_par* par;
	struct mng_pars* pars;

} mng_pars; //parametros




/*
parametros : 
	| parametro 
	| parametro VIRG parametros
; 
*/


/*
typedef struct {
	//DEC(if); //?
	//DEC(apar);
	//DEC(exp);
	//DEC(fpar);
	DEC(cmd);
	//DEC(parteelse); 
    
} mng_cmd1; //comando

/*
typedef struct {
    union{
       // mng_if 
    };
} mng_cmd; //comando
/*
comando : IF APAR exp FPAR comando parteelse
        | WHILE APAR exp FPAR comando
        | var ATRIB exp PTVIRG
        | RETURN exp PTVIRG
		| RETURN PTVIRG
		| chamadaMetodo PTVIRG
		| bloco
;
*/



typedef struct  mng_decfunc{
	DEC(tip);
	DEC(id);
	mng_pars* pars;
	DEC(bloco);
} mng_decfunc ; //decfunção

/*
decfuncao : VOID ID APAR parametros FPAR bloco {}
	|tipo ID APAR parametros FPAR bloco	
;
*/







typedef struct mng_dec{
	tipo_no tipodec;
    union{
        DEC(decvar);
        DEC(decfunc);
    };
} mng_dec; //declaracao
/*
programa : 
           | declaracao programa 
; 
*/





/*typedef struct { 
		//dúvida
} mng_vazio;
*/

/*
typedef struct { 
    DEC(dec);
    DEC(pgr);
} mng_pgr2;
*/

typedef struct mng_prg {
	DEC(dec);
	struct mng_prg* prog; //= NULL;
	int teste;
//	mng_dec* listadec;
} mng_prg; //programa

/*
declaracao : decvariavel  { char* c = $1.tipo; printf("tipo: %s",c);}
	| decfuncao
;
*/




typedef struct no_ast {
    tipo_no tipo;
	struct No_ast* a;
    union {
		mng_prg prg;
		        
        
    } val;
} No_ast; // nó da árvore


/*
mng_prg* inicializaprog(mng_dec dec,mng_prg* prg,int t){
	int tamanho= sizeof(mng_prg);
	mng_prg* programa = (mng_prg*) malloc(tamanho);
	(*programa).dec = dec;
	(*programa).prog= prg;
	(*programa).teste= t;
	return programa;
} */

mng_prg* inicializaprog(mng_dec dec,mng_prg* prg){
	int tamanho= sizeof(mng_prg);
	DECP(prg) = (mng_prg*) malloc(tamanho);
	(*p_prg).dec = dec;
	(*p_prg).prog= prg;
	
//	(*p_prg).teste= t;
	return p_prg;
}


mng_decfunc inicializadecfunc(DEC(id),mng_pars * pars, DEC(bloco)){
	int tamanho= sizeof(mng_decfunc);
	DECP(decfunc) = (mng_decfunc*) malloc(tamanho);
	(*p_decfunc).id = id;
	(*p_decfunc).pars = pars;
	(*p_decfunc).bloco = bloco;
	return *p_decfunc;
}

mng_bloco inicializabloco(mng_decvars* decvars, mng_cmds* cmds){
	int tamanho= sizeof(mng_bloco);
	DECP(bloco) = (mng_bloco*) malloc(tamanho);
	(*p_bloco).decvars = decvars;
	(*p_bloco).cmds = cmds;

	return *p_bloco;
}

mng_listnom* inicializalistnom(DEC(id),mng_listnom* listnom){
	int tamanho= sizeof(mng_listnom);
	DECP(listnom) = (mng_listnom*) malloc(tamanho);
	(*p_listnom).id = id;
	(*p_listnom).list= listnom;
/*	(*p_dec).teste= t; */
	return p_listnom;
}

mng_pars* inicializapars(DEC(par),mng_pars* pars){
	int tamanho= sizeof(mng_pars);
	DECP(pars) = (mng_pars*) malloc(tamanho);
	(*p_pars).par = &par;
	(*p_pars).pars= pars;
/*	(*p_dec).teste= t; */
	return p_pars;
}

mng_par inicializapar(DEC(tip),mng_id id){
	int tamanho= sizeof(mng_par);
	DECP(par) = (mng_par*) malloc(tamanho);
	(*p_par).tip = tip;
	(*p_par).id = id;
/*	(*p_dec).teste= t; */
	return (*p_par);
}


mng_var inicializavar(mng_exp* exp){
	int tamanho= sizeof(mng_var);
	DECP(var) = (mng_var*) malloc(tamanho);
	(*p_var).exp = exp;
	return (*p_var);
}


mng_decvar inicializadecvar(DEC(tip),DECP(listnom)){
	int tamanho= sizeof(mng_decvar);
	DECP(decvar) = (mng_decvar*) malloc(tamanho);
	(*p_decvar).tip = tip;
	(*p_decvar).p_listnom= p_listnom;
/*	(*p_dec).teste= t; */
	return (*p_decvar);
}

mng_decvars * inicializadecvars(mng_decvar decvar,mng_decvars* decvars){
	int tamanho= sizeof(mng_decvars);
	DECP(decvars) = (mng_decvars*) malloc(tamanho);
	(*p_decvars).decvar = decvar;
	(*p_decvars).decvars= decvars;
	return p_decvars;
}

mng_cmds * inicializacmds(mng_cmd cmd,mng_cmds* cmds){
	int tamanho= sizeof(mng_cmds);
	DECP(cmds) = (mng_cmds*) malloc(tamanho);
	(*p_cmds).cmd = cmd;
	(*p_cmds).cmds= cmds;
	return p_cmds;

}

mng_dec inicializadec(){
	int tamanho= sizeof(mng_dec);
	DECP(dec) = (mng_dec*) malloc(tamanho);
/*	(*p_dec).decvar = decvar;
	(*p_dec).decfunc= decfunc;
	(*p_dec).teste= t; */
	return *p_dec;
}

mng_tip inicializatipo(){
	int tamanho= sizeof(mng_tip);
	DECP(tip) = (mng_tip*) malloc(tamanho);
/*	(*p_dec).decfunc= decfunc;
	(*p_dec).teste= t; */
	
	return *p_tip;
}


mng_ptelse * inicializaptelse(mng_cmd cmd){
	int tamanho= sizeof(mng_ptelse);
	DECP(ptelse) = (mng_ptelse*) malloc(tamanho);
	(*p_ptelse).cmd = &cmd;
	return p_ptelse;
}

mng_cmd inicializacmd(tipo_no tipocmd){
	int tamanho= sizeof(mng_cmd);
	DECP(cmd) = (mng_cmd*) malloc(tamanho);
	(*p_cmd).tipocmd = tipocmd;
	return (*p_cmd);
}

mng_chmet inicializachmet(DEC(id), mng_listexp * listexp){
	int tamanho= sizeof(mng_chmet);
	DECP(chmet) = (mng_chmet*) malloc(tamanho);
	(*p_chmet).id = id;
	(*p_chmet).listexp = listexp;
	return (*p_chmet);
}
mng_listexp * inicializalistexp(DEC(exp), mng_listexp* listexp){
	int tamanho= sizeof(mng_listexp);
	DECP(listexp) = (mng_listexp*) malloc(tamanho);
	(*p_listexp).exp = exp;
	(*p_listexp).listexp = listexp;
	return p_listexp;
}

mng_exp inicializaexp(tipo_no tipoexp){
	int tamanho= sizeof(mng_exp);
	DECP(exp) = (mng_exp*) malloc(tamanho);
	(*p_exp).tipoexp = tipoexp;
	return (*p_exp);
}


void printdecfunc(mng_decfunc* p ){
		int teste=1;
		//if ( (*p).tipodec == MNG_DECVAR ){
			printf("decfunc->tipo %d decfunc->listanome\n",teste);
//			printdecvar(&(*p).decvar);
		//}


}

void printlistnom(mng_listnom* p ){
		int teste=1;
		while (p!=NULL){
				printf("listnome:  %s \n",(*p).id.name);

				//printid(&(*p).dec);
				p=(*p).list;
				teste++;
		}
		//printf("prg: %d \n",(*p).teste);

}



void printdecvar(mng_decvar* p ){
		int teste=1;
		//if ( (*p).tipodec == MNG_DECVAR ){
			printf("decvar->tipo %d decvar->listanome %d\n",(*p).tip.tipbase,teste);
			printlistnom((*p).p_listnom);
//			printdecvar(&(*p).decvar);
		//}


}




void printdec(mng_dec* p ){
		int teste=1;
		if ( (*p).tipodec == MNG_DECVAR ){
			printf("decvar: %d\n",teste);
			printdecvar(&(*p).decvar);
		}
		else{
			printf("decfunc: %d\n",teste);
			printdecfunc(&(*p).decfunc);
		}
		//teste++;
				
		//while (p!=NULL){
		//		printf("prg: %d \n",teste);
				//p=(*p).;
		//		teste++;
		//}
		//printf("prg: %d \n",(*p).teste);
	
}


void printprg(mng_prg* p ){
		int teste=1;
		while (p!=NULL){
				printf("prg: %d \n",teste);
				printdec(&(*p).dec);
				p=(*p).prog;
				teste++;
		}
		//printf("prg: %d \n",(*p).teste);
	
}




void printarv(){
	
}





/*
#define STRUCT(tipo_struct,atr1,atr2,atr3,atr4,atr5) typedef struct  { atr1;atr2;atr3;atr4;atr5; } mng_##tipo_struct
*/

/*void monga_prog_appende_decl(struct monga_prog* p, struct monga_decl* decl) {
    struct decl_list* last = decl_list_last(p->decl_list);
    last->next = create_decl_list_node(decl);
} */

/*

enum {MNG_PROG,MNG_DEC,MNG_DECVAR,MNG_LISTNOM,MNG_TIPO,MNG_TIPBASE,MNG_DECFUNC,MNG_PARS,
MNG_PAR,MNG_BLOCO,MNG_DECVARS,MNG_CMD,MNG_CMDS,MNG_PTELSE,MNG_VAR,MNG_EXP,MNG_CHMDMET,MNG_LSTEXP} tipo_no;

struct {
    enum tipo_no type;
    union {
        struct mng_var var;
        struct mng_if if_stmt;
    } val;
} no_ast; // nó da árvore

#define ALLOC_NODE struct monga_node* node = \
        (struct monga_node*) malloc(sizeof(struct monga_node))
#define FIELD(field) (node->val.field = field)
#define RET_NODE(t) node->type = t; return node
#define CTOR(suffix) struct monga_##suffix* create_##suffix

CTOR(var) (char* ident) {
    ALLOC_NODE;
    FIELD(ident);
    RET_NODE(MNG_VAR);
}

CTOR(prog) () {
    ALLOC_NODE;
    RET_NODE(MNG_PROG);
} */
