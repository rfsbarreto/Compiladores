#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {MNG_PROG,MNG_DEC,MNG_DECVAR,MNG_LISTNOM,MNG_TIPO,MNG_TIPBASE,MNG_DECFUNC,MNG_PARS, MNG_IF, MNG_WHILE,MNG_ATRIB, MNG_OP, MNG_NAO, MNG_TIPEXP, MNG_RETURN, MNG_OPNEG,
MNG_PAR,MNG_BLOCO,MNG_DECVARS,MNG_CMD,MNG_CMDS,MNG_PTELSE,MNG_VAR,MNG_EXP,MNG_CHMET,MNG_LSTEXP} tipo_no;

typedef enum mng_tipbase { 
	TIPO_INT,TIPO_CHAR,TIPO_STRING,TIPO_FLOAT,TIPO_VAZIO
} mng_tipbase ; //tipobase

typedef enum mng_tipret { 
	RET_VAZIO, RET_EXP
} mng_tipret ; //tiporet


typedef enum mng_operadores { 
	OP_NAO, OP_SOMA, OP_SUB, OP_MULT, OP_DIV, OP_IGUAL, OP_MENORIG, OP_MAIORIG, OP_MENORQ, OP_MAIORQ, OP_OU, OP_E
} mng_operadores ; //operadores

typedef struct mng_linha_rec{
	int linha;
	struct mng_linha_rec * proximo;
}* mng_linha;

typedef struct mng_buckets_rec{
		char *nome;
		mng_linha linha;
		int memloc;
		struct mng_buckets_rec * proximo;
}* mng_buckets;




typedef struct mng_id{
    char* name;
} mng_id;


typedef struct mng_numint{
     int valor;
} mng_numint;

typedef struct mng_numfloat{
    float valor;
} mng_numfloat;

typedef struct mng_chr{
    char valor;
} mng_chr;

typedef struct mng_string{
    char* valor;
	mng_tipbase tipo;
} mng_string;


typedef struct mng_chmet{
	struct mng_id id;
	struct mng_listexp* listexp;
}mng_chmet;


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


typedef struct mng_op{
	int linha;
	mng_exp exp1;
	mng_operadores op;
	mng_exp exp2; 
}mng_op;


typedef struct mng_tip{
	DEC(tipbase);
}mng_tip;


typedef struct mng_var{
	DEC(id);
	mng_exp * exp;
} mng_var;


typedef struct { 
	DEC(id);
} mng_listnom2 ; //listanomes

typedef struct mng_listnom { 
		DEC(id);
		struct mng_listnom* list;
} mng_listnom ; //listanomes


typedef struct mng_decvar{ 
    DEC(tip);
    DECP(listnom);
} mng_decvar ;   // decvariavel


typedef struct mng_decvars{
	mng_decvar decvar;
	struct mng_decvars* decvars;

} mng_decvars;


typedef struct mng_atrib{
	DEC(var);
	DEC(exp);
} mng_atrib;


typedef struct mng_ptelse{
	struct mng_cmd* cmd;
} mng_ptelse;


typedef struct mng_decif { 
//    char* name;
	DEC(exp);
	struct mng_cmd* cmd;
	mng_ptelse* ptelse;
	
} mng_decif;

typedef struct mng_decwhile { 
	DEC(exp);
	struct mng_cmd* cmd;
	
} mng_decwhile;


typedef struct mng_ret{
	mng_tipret tipret;
	union{
		mng_exp exp;	
	};
}mng_ret;

typedef struct mng_cmd{
	tipo_no tipocmd;
	int linha;
	union{
		DEC(decif);
		DEC(decwhile);
		DEC(atrib);
		struct mng_bloco* bloco;
		mng_ret ret;
		DEC(chmet);
	};
} mng_cmd;




typedef struct mng_cmds{
	mng_cmd cmd;
	struct mng_cmds* cmds;
} mng_cmds;


typedef struct mng_bloco{ 

	mng_decvars* decvars;
	mng_cmds* cmds;
} mng_bloco ; //bloco


typedef struct mng_par{
    DEC(tip);
    DEC(id);
} mng_par ; //parametro


typedef struct mng_pars{
	struct mng_par* par;
	struct mng_pars* pars;

} mng_pars; //parametros


typedef struct  mng_decfunc{
	DEC(tip);
	DEC(id);
	mng_pars* pars;
	DEC(bloco);
} mng_decfunc ; //decfunção


typedef struct mng_dec{
	tipo_no tipodec;
    union{
        DEC(decvar);
        DEC(decfunc);
    };
} mng_dec; //declaracao


typedef struct mng_prg {
	DEC(dec);
	struct mng_prg* prog; //= NULL;
	int teste;
} mng_prg; //programa

typedef struct simbolo{
        mng_tipbase tipo;
        char* name;

} simbolo;


typedef struct funcao{
        mng_tipbase tipo;
        char* name;
		struct lista_simb* lista;
} funcao;

typedef struct lista_simb{
        int tipono;
        union{
                 simbolo simb;
                funcao funcao;
        };
        struct lista_simb* prox;
} lista_simb;

lista_simb* adicionaVar(lista_simb* s,mng_decvar decvar){
			printf("adicionavar %s \n",(*decvar.p_listnom).id.name);
        	mng_listnom var = (*decvar.p_listnom);
			lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).simb.name=var.id.name;
        	(*sim).simb.tipo=decvar.tip.tipbase;
        	(*sim).tipono=0;
			printf("simbolo %s %d \n",(*sim).simb.name,(*sim).simb.tipo);
			if (s!=NULL){
				printf("s not null \n");
				(*sim).prox=(*s).prox;
				(*s).prox=sim;			// cabeça apontará para o nó atual
//				(*sim).prox=(*s).prox;
				//return s;
    		}else{
				printf("s null \n");
				s= (lista_simb*) malloc(sizeof(lista_simb));            
				(*s).prox=sim;
				if (s==NULL){
					printf("comoooo vá");}						
				//(*s).prox=sim;
				//return s;
			}
		while (var.list!=NULL){
			var=(*var.list);			
			sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).simb.name=var.id.name;
        	(*sim).simb.tipo=decvar.tip.tipbase;
        	(*sim).tipono=0;
        	(*sim).prox=(*s).prox;   //novo no aponta pra quem a cabeça está apontando
			(*s).prox=sim;			// cabeça apontará para o nó atual
			
        }
		return s;

}

lista_simb* adicionaFunc(lista_simb* s,mng_decfunc decfunc){
			printf("adicionavar %s \n",decfunc.id.name);
        	//mng_listnom var = (*decvar.p_listnom);
			lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).funcao.name=decfunc.id.name;
        	(*sim).simb.tipo=decfunc.tip.tipbase;
        	(*sim).tipono=1;
			printf("simbolo %s %d \n",(*sim).simb.name,(*sim).simb.tipo);
			if (s!=NULL){
				printf("s not null \n");
				(*sim).prox=(*s).prox;
				(*s).prox=sim;			// cabeça apontará para o nó atual
//				(*sim).prox=(*s).prox;
				//return s;
    		}else{
				printf("s null \n");
				s= (lista_simb*) malloc(sizeof(lista_simb));            
				(*s).prox=sim;
				if (s==NULL){
					printf("comoooo vá");}						
				//(*s).prox=sim;
				//return s;
			}
			return s;

}

void imprimirlista(lista_simb* s){
		printf("implista ");
		lista_simb* aux=s;
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;				
			printf("var: %s  ",(*aux).simb.name);
			
        }
}


/*
typedef struct no_ast {
    tipo_no tipo;
	struct No_ast* a;
    union {
		mng_prg prg;
    } val;
} No_ast; */ // nó da árvore 
