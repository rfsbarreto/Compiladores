%{ 
//#include <stdio.h>
//#include "bib1.c"
#include "bib_inic.h"
//#include "teste.h"
#include "lex.c"
#define YYDEBUG 1
//#define DEC(dec) mng_##dec dec
//extern mng_tipbase ;

//No_ast* arvore;

mng_prg* arvore;

//int test=1;

void yyerror(const char* errmsg);




%}
%token CHAR ELSE FLOAT IF INT NEW RETURN VOID WHILE 

%token NUMINT NUMFLOAT STRING  

%token ID PTVIRG VIRG ACOL FCOL APAR FPAR ACHAVE FCHAVE

%token SOMA SUB MULT DIV ATRIB IGUAL MENORIG MAIORIG MENORQ MAIORQ NAO E OU		

%union{
	
	mng_tipbase  tipbase;	
	mng_id id;
	mng_var var;
	DEC(bloco);
	mng_pars * pars;
	mng_par par;
	mng_decvar decvar;
	mng_decfunc decfunc;
	mng_tip tip;
	mng_prg* prg;
	mng_dec dec;
	mng_listnom* listnom;
	mng_decvars* decvars;
	mng_cmds* cmds;
	mng_cmd cmd;
	mng_ptelse* ptelse;
	mng_chmet chmet;
	mng_listexp* listexp;
	mng_exp exp;
	DEC(numint);
	DEC(numfloat);
	DEC(string);
	//DEC(prg);
	//int token;
}



%type <id> ID
%type <inteiro> ATRIB
%type <string> STRING
%type <numfloat> NUMFLOAT
%type <numint> NUMINT
%type <int> IF WHILE
%type <var> var
%type <listexp> listaexp 
%type <exp> exp
//%type <string> 
%type <ptelse> parteelse
%type <tipbase> tipobase
%type <bloco> bloco
%type <cmd> comando
%type <cmds> comandos
%type <tip> tipo
%type <par> parametro
%type <pars> parametros
%type <decvar> decvariavel
%type <decvars> decvariaveis
%type <decfunc> decfuncao
%type <dec> declaracao
%type <prg> programa
%type <listnom> listanomes
%type <chmet> chamadaMetodo
//%type <string> tipo;
//%type <string> tipobase;



%left MULT DIV
%left SOMA SUB
%right IGUAL MENORQ MENORIG MAIORQ MAIORIG
%left E OU
%nonassoc NAO

%error-verbose

%%

principal: programa { arvore= $1;  };

programa : {printf("vazio\n"); $$=NULL; } // $$.teste = test;
           | declaracao programa {   $$=inicializaprog($1,$2); }
; 

declaracao : decvariavel  { $$=inicializadec(); $$.decvar =$1; $$.tipodec=MNG_DECVAR;}//
	| decfuncao {  $$=inicializadec(); $$.decfunc =$1;  $$.tipodec=MNG_DECFUNC;}
;

decvariavel : tipo listanomes PTVIRG { $$=inicializadecvar($1,$2); }
;

listanomes : ID { $$=inicializalistnom($1,NULL); }
	| ID VIRG listanomes  {  $$=inicializalistnom($1,$3); }
					//|  {}|
;

//id: ID  {}   ;

//tiporetorno: tipo ID 
//		| VOID ID;

tipo : tipobase  { $$.tipbase = $1;  } //$.tipbase=$1; }
	| tipo ACOL FCOL {$$=inicializatipo();}// $.tip=  }
;

tipobase : INT {  $$=TIPO_INT; }
	| CHAR { $$=TIPO_INT;}
	| FLOAT { $$=TIPO_FLOAT; }
; 

decfuncao : VOID ID APAR parametros FPAR bloco {$$=inicializadecfunc($2, $4, $6); $$.tip.tipbase = TIPO_VAZIO; }
	| tipo ID  APAR parametros FPAR bloco {$$=inicializadecfunc($2, $4, $6); $$.tip = $1; printf("FUNÇÃO %s",$2.name);            }	
;

//tiporetorno : tipo | VOID;


parametros : {$$ = NULL;}
	| parametro {$$ = inicializapars($1, NULL);}
	| parametro VIRG parametros {$$ = inicializapars($1, $3);}
; 

parametro : tipo ID  { $$ = inicializapar($1, $2);};

bloco : ACHAVE decvariaveis comandos FCHAVE {$$ = inicializabloco($2, $3);}
;
		
decvariaveis : decvariavel  decvariaveis { $$ = inicializadecvars($1,$2); }
	| {$$ = NULL;}
;

comandos: comando comandos {$$ = inicializacmds($1,$2);}
	|  {$$ = NULL;}
;
		
comando : IF APAR exp FPAR comando parteelse {$$= inicializacmd(MNG_IF); $$.decif.exp = $3; $$.decif.cmd = &($5); $$.decif.ptelse = $6;}
        | WHILE APAR exp FPAR comando {$$= inicializacmd(MNG_WHILE); $$.decwhile.exp=$3; $$.decwhile.cmd = &($5); }
        | var ATRIB exp PTVIRG {$$= inicializacmd(MNG_ATRIB); $$.atrib.var = $1; $$.atrib.exp = $3; }
        | RETURN exp PTVIRG {$$= inicializacmd(MNG_RETURN); $$.exp = &($2);}
	| RETURN PTVIRG {$$= inicializacmd(MNG_RETURN); $$.exp = NULL;}
	| chamadaMetodo PTVIRG {$$= inicializacmd(MNG_CHMET); $$.chmet= $1;}
	| bloco {$$=inicializacmd(MNG_BLOCO); $$.bloco = &($1);}
;







parteelse :           {$$ = NULL;}
	| ELSE comando {$$ = inicializaptelse($2);} //precisa verificar se está correto
;

var : ID  { $$ = inicializavar(NULL); $$.id = $1; }// $$.id=$1; }
	| var ACOL exp FCOL {$$=inicializavar(&($3));}
;

exp : NUMINT { $$=inicializaexp(MNG_TIPBASE);    $$.tipo = TIPO_INT; $$.numint=$1;}
	| NUMFLOAT {$$=inicializaexp(MNG_TIPBASE); $$.tipo=  TIPO_FLOAT; $$.numfloat=$1;   }
	| STRING {$$=inicializaexp(MNG_TIPBASE); $$.tipo= TIPO_STRING; $$.string=$1; }
	| var{$$=inicializaexp(MNG_VAR); $$.var= &$1;}                 
	| APAR exp FPAR{$$=inicializaexp(MNG_EXP); $$.exp= &$2;}
	| chamadaMetodo {$$=inicializaexp(MNG_CHMET); $$.chmet= $1;}
    	| NEW tipo ACOL exp FCOL {$$=inicializaexp(MNG_TIPEXP); $$.tipexp.tip = &$2; $$.exp = &$4;}
	| SUB exp {
			$$=inicializaexp(MNG_TIPBASE); $$.tipo = $2.tipo; 
			($2.tipo=TIPO_INT)?($$.numint.valor=(-1 * $2.numint.valor)):($$.numfloat.valor=(-1*$2.numfloat.valor)); 
		  }  
	| exp SOMA exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_SOMA; (*$$.op).exp2 = $3; }
	| exp SUB exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_SUB; (*$$.op).exp2 = $3;}
	| exp MULT exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_MULT; (*$$.op).exp2 = $3;}
	| exp DIV exp  {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_DIV; (*$$.op).exp2 = $3;}
	| exp IGUAL exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_IGUAL; (*$$.op).exp2 = $3;}
	| exp MENORIG exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_MENORIG; (*$$.op).exp2 = $3;}
	| exp MAIORIG exp  {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_MAIORIG; (*$$.op).exp2 = $3;}
	| exp MENORQ exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_MENORQ; (*$$.op).exp2 = $3;}
	| exp MAIORQ exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_MAIORQ; (*$$.op).exp2 = $3;}
	| NAO exp {$$=inicializaexp(MNG_NAO); $$.nao.op = OP_NAO; $$.nao.exp = &($2);}
	| exp E exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_E; (*$$.op).exp2 = $3;}
	| exp OU exp {$$=inicializaexp(MNG_OP); (*$$.op).exp1= $1; (*$$.op).op= OP_OU; (*$$.op).exp2 = $3;}
;

/*
typedet struct mng_nao{
	DEC(operadores) = OP_NAO;
	struct DEC(exp);
}mng_nao;

typedef struct mng_exp{
	union{
		DEC(tipbase);
		DEC(var);
		struct DEC(exp);
		DEC(chmet);
		DEC(op);
		DEC(mng_nao);
	}
}mng_exp;


typedef struct mng_op{
	mng_exp exp;
	DEC(operadores);
	mng_exp exp; 
}mng_op;
*/
chamadaMetodo : ID APAR listaexp FPAR {$$ = inicializachmet($1,$3);}
;

listaexp :  {$$ = NULL;}
			| exp {$$ = inicializalistexp($1, NULL);}
			| exp VIRG listaexp {$$ = inicializalistexp($1, $3);}
;

%%

void yyerror(const char* errmsg)
{
	printf("\n***Linha %d: Erro: %s\n", lineno, errmsg);
}

//int yywrap() { return 1; }
	


 
int main(int argc, char** argv){
	extern yydebug;
	yydebug=1;
        yyparse();

	printf("acabou o/ \n");
//	printf("arvore: %d \n",(*arvore).teste);
//	mng_prg p = 	(*arvore).prog;
//	printf("arvore2: %d \n",(*arvore).prog.teste);
//	printprg(arvore);
     return 0;
}

