%{ 
//#include <stdio.h>
//#include "bib1.c"
#include "bib_inic.h"

//#include "teste.h"
#include "lex.c"
//#define YYDEBUG 1
//#define DEC(dec) mng_##dec dec
//extern mng_tipbase ;

//No_ast* arvore;
lista_simb* tbl;
mng_prg* arvore;
pilha* p;


void yyerror(const char* errmsg);




%}
%token CHAR ELSE FLOAT IF INT NEW RETURN VOID WHILE 

%token NUMINT NUMFLOAT STRING  

%token ID PTVIRG VIRG ACOL FCOL APAR FPAR ACHAVE FCHAVE

%token SOMA SUB MULT DIV ATRIB IGUAL MENORIG MAIORIG MENORQ MAIORQ NAO E OU		

%union{
	
	mng_tipbase  tipbase;	
	mng_id id;
	mng_var* var;
	mng_bloco * bloco;
//	DEC(bloco);
	mng_pars * pars;
	mng_par* par;
	mng_decvar* decvar;
	mng_decfunc* decfunc;
	mng_tip* tip;
	mng_prg* prg;
	mng_dec* dec;
	mng_listnom* listnom;
	mng_decvars* decvars;
	mng_cmds* cmds;
	mng_cmd* cmd;
	mng_ptelse* ptelse;
	mng_chmet* chmet;
	mng_listexp* listexp;
	mng_exp* exp;
	DEC(numint);
	DEC(numfloat);
	DEC(string);
	DEC(chr);
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

principal: programa {   arvore= $1; 

//			PercorreArvore($1);	
}// imprimirlista(tbl);  };

programa : { $$=NULL; } // $$.teste = test;
           | declaracao programa {   $$=inicializaprog($1,$2); }
; 

declaracao : decvariavel  { $$=inicializadec(); 
			(*$$).decvar =$1; 
			(*$$).tipodec=MNG_DECVAR;
			//tbl=adicionaVar(tbl,$1.p_listnom,$1.tip); 
		//	verificasimbolos(tbl,$1.p_listnom);
		//	imprimirlista(tbl);
			}
	| decfuncao {  $$=inicializadec(); 
			(*$$).decfunc =$1;  
			(*$$).tipodec=MNG_DECFUNC;
		//	tbl=adicionaFunc(tbl,$1); 
		//	verificasimbolo(tbl,$1.id);
		//	imprimirlista(tbl);
}
;

decvariavel : tipo listanomes PTVIRG { $$=inicializadecvar($1,$2);  }
;

listanomes : ID { $$=inicializalistnom($1,NULL); 
					//verificaIDDuplicado(tbl, $1);
		}
	| ID VIRG listanomes  {  $$=inicializalistnom($1,$3); }
;


tipo : tipobase  { $$=inicializatipo(); (*$$).tipbase = $1; (*$$).qtdACOL= 0;}
	| tipo ACOL FCOL { 
			$$=inicializatipo();
			(*$$).tipbase = (*$1).tipbase;			
			(*$$).qtdACOL =(*$1).qtdACOL+1;
			}
;

tipobase : INT {  $$=TIPO_INT;}
	| CHAR { $$=TIPO_CHAR;}
	| FLOAT { $$=TIPO_FLOAT;}
; 

decfuncao : VOID ID APAR parametros FPAR bloco {$$=inicializadecfunc($2, $4, $6);
							(*$$).tip = inicializatipo(); 
						(*(*$$).tip).tipbase = TIPO_VAZIO;
						//lista_simb* tblaux=adicionaVars(tblaux,$6);
						//verificasimbolosbloco(tblaux,$6);
						//tbl=adicionaFunc(tbl,$$,$4,tblaux);  
					//	imprimirlista(tblaux);
						//verificaIDDuplicado(tbl, $2);
						if ($4 != NULL){
						(*$$).qtdPars = (*$4).qtdPars;}else (*$$).qtdPars =0;
				//		verificaReturn($6, (*$$).tip, $2);
						}	
	| tipo ID  APAR parametros FPAR bloco {$$=inicializadecfunc($2, $4, $6);
						(*$$).tip = inicializatipo();  
						(*$$).tip = $1;
						if ($4 != NULL) {
						(*$$).qtdPars = (*$4).qtdPars;} else (*$$).qtdPars =0;
						//lista_simb* tblaux1=adicionaVars(tblaux1,$6);
						//tbl=adicionaFunc(tbl,$$,$4,tblaux1);  
						//imprimirlista(tblaux1);
						//verificasimbolosbloco(tblaux1,$6);
			//			verificaIDDuplicado(tbl, $2);
//						verificaReturn($6, (*$$).tip, $2);       
}	
;

//tiporetorno : tipo | VOID;


parametros : {$$ = NULL; //(*$$).qtdPars = 0;
}
	| parametro {$$ = inicializapars($1, NULL); (*$$).qtdPars =1;
}
	| parametro VIRG parametros {$$ = inicializapars($1, $3); if ($3 != NULL){(*$$).qtdPars = (*$3).qtdPars +1;} else (*$$).qtdPars= 1;
}
; 

parametro : tipo ID  { $$ = inicializapar($1, $2);};

bloco : ACHAVE decvariaveis comandos FCHAVE {$$ = inicializabloco($2, $3);}
;
		
decvariaveis : decvariavel  decvariaveis { $$ = inicializadecvars($1,$2); }
	| {$$ = NULL;}
;

comandos: comando comandos {$$ = inicializacmds($1,$2); (*$$).cmd = $1;  (*$$).cmds = $2;
			}
	|  {$$ = NULL;}
;
		
comando : IF APAR exp FPAR comando parteelse {$$= inicializacmd(MNG_IF); 
					(*$$).decif.exp = $3; 
					(*$$).decif.cmd = $5; 
					(*$$).decif.ptelse = $6; (*$$).linha=lineno;}
        | WHILE APAR exp FPAR comando {$$= inicializacmd(MNG_WHILE); 
					(*$$).decwhile.exp=$3; 
					(*$$).decwhile.cmd = $5;
					(*$$).linha=lineno;}
        | var ATRIB exp PTVIRG {$$= inicializacmd(MNG_ATRIB);
				(*$$).atrib= inicializaatrib($1,$3);	
			 
//				(*$$).atrib.var = $1; 
//				(*$$).atrib.exp = $3; 
				(*$$).linha=lineno;}
        | RETURN exp PTVIRG {$$= inicializacmd(MNG_RETURN); 
				(*$$).ret.exp = $2; 
				(*$$).ret.tipret=RET_EXP; 
				(*$$).linha=lineno; }
	| RETURN PTVIRG {$$= inicializacmd(MNG_RETURN); 
					(*$$).ret.tipret=RET_VAZIO; (*$$).linha=lineno;  }
	| chamadaMetodo PTVIRG {$$= inicializacmd(MNG_CHMET); (*$$).chmet= $1;(*$$).linha=lineno;}
	| bloco {$$=inicializacmd(MNG_BLOCO); (*$$).bloco = ($1);(*$$).linha=lineno;
			}
;


parteelse :           {$$ = NULL;}
	| ELSE comando {$$ = inicializaptelse($2);} //precisa verificar se está correto
;

var : ID  { $$ = inicializavar(NULL); (*$$).tip = inicializatipo(); (*$$).id = $1; (*$$).qtdACOL=0; }
	| var ACOL exp FCOL {$$=inicializavar($3); (*$$).id=(*$1).id; (*$$).tip = inicializatipo();  (*$$).qtdACOL=(*$1).qtdACOL+1;}
;

exp : NUMINT { $$=inicializaexp(MNG_TIPBASE);  
				(*$$).tipo = inicializatipo();		  
		(*(*$$).tipo).tipbase =TIPO_INT; 
		(*$$).numint=$1;}
	| NUMFLOAT {$$=inicializaexp(MNG_TIPBASE); 
				(*$$).tipo = inicializatipo();	
		(*(*$$).tipo).tipbase=TIPO_FLOAT;
		(*$$).numfloat=$1;   
		}
	| STRING {$$=inicializaexp(MNG_TIPBASE);
			(*$$).tipo = inicializatipo(); 
			(*(*$$).tipo).tipbase= $1.tipo; 
			(*$$).string=$1; }
	| var {$$=inicializaexp(MNG_VAR); 
			
		(*$$).var= $1; 
		(*(*$$).var).qtdACOL= (*$1).qtdACOL; 
		}                 
	| APAR exp FPAR{$$=inicializaexp(MNG_EXP); 
			(*$$).exp= $2; 
			(*$$).tipo = inicializatipo();	
			(*(*$$).tipo).tipbase = (*(*(*$$).exp).tipo).tipbase;
			}
	| chamadaMetodo {$$=inicializaexp(MNG_CHMET); (*$$).chmet= $1;}
    	| NEW tipo ACOL exp FCOL {$$=inicializaexp(MNG_TIPEXP); 
			(*$$).tipexp.tip = inicializatipo();
			(*$$).tipexp.tip = $2; 
			(*$$).exp = $4;}
	| SUB exp {
			$$=inicializaexp(MNG_TIPBASE); 
			(*$$).tipo = inicializatipo();
			(*(*$$).tipo).tipbase = (*(*$2).tipo).tipbase; 
			((*(*$2).tipo).tipbase==TIPO_INT)?((*$$).numint.valor=(-1 * (*$2).numint.valor)):((*$$).numfloat.valor=(-1*(*$2).numfloat.valor)); 
		  }  
	| exp SOMA exp {
			$$=inicializaexp(MNG_OP);
			(*$$).op=inicializaop($1,OP_SOMA,$3); 
			(*(*$$).op).linha = lineno;
			(*$$).tipo = inicializatipo();
		
			//(*(*$$).tipo).tipbase=verificatipoexpOP($1,$3);
			}

	| exp SUB exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_SUB,$3);  
			(*(*$$).op).linha = lineno;
(*$$).tipo = inicializatipo();
	//		(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
	| exp MULT exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_MULT,$3);  
			(*(*$$).op).linha = lineno;
			(*$$).tipo = inicializatipo();
			int tamanho= sizeof(mng_tipbase);
			(*(*$$).tipo).tipbase = (mng_tipbase) malloc(tamanho);
	
 			(*(*$$).tipo).tipbase = TIPO_CHAR;
			//(*(*$$).tipo).tipbase=verificatipoexpOP($1,$3);
			}
	| exp DIV exp  {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_DIV,$3);  
			(*(*$$).op).linha = lineno;

			(*$$).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
	| exp IGUAL exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_IGUAL,$3);
			(*(*$$).op).linha = lineno;
			(*$$).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
	| exp MENORIG exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_MENORIG,$3); 
			(*(*$$).op).linha = lineno;
			(*$$).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
	| exp MAIORIG exp  {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_MAIORIG,$3);  
			(*(*$$).op).linha = lineno;
			(*$$).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
	| exp MENORQ exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_MENORQ,$3);  
			(*(*$$).op).linha = lineno;
			(*$$).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
	| exp MAIORQ exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_MAIORQ,$3); 
			(*(*$$).op).linha = lineno; 
			(*$$).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}//(*$$.op).exp1= $1; (*$$.op).op= OP_MAIORQ; (*$$.op).exp2 = $3;}
	| NAO exp {	$$=inicializaexp(MNG_NAO); 
			(*$$).nao.op = OP_NAO; 
			(*$$).nao.exp = $2; 
			(*$$).tipo= inicializatipo();
			(*(*$$).tipo).tipbase = (*(*$2).tipo).tipbase;}
	| exp E exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_E,$3); 
//			(*(*$$).op).exp1= $1; 
//			(*(*$$).op).op= OP_E; 
//			(*(*$$).op).exp2 = $3;
			(*(*$$).op).linha = lineno;
			(*$$).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			} //verificar o tipo
	| exp OU exp {$$=inicializaexp(MNG_OP); 
			(*$$).op=inicializaop($1,OP_OU,$3);
			//(*(*$$).op).exp1= $1; 
			//(*(*$$).op).op= OP_OU; 
			//(*(*$$).op).exp2 = $3;
			(*(*$$).op).linha = lineno;
			(*$$).tipo= inicializatipo();
//			(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
}
;

chamadaMetodo : ID APAR listaexp FPAR {$$ = inicializachmet($1,$3);}
;

listaexp :  {$$ = NULL;// (*$$).qtdPars = 0;
}
			| exp {$$ = inicializalistexp($1, NULL); (*$$).qtdPars = 1;
}
			| exp VIRG listaexp {$$ = inicializalistexp($1, $3); (*$$).qtdPars = (*$3).qtdPars +1;
}
;

%%

void yyerror(const char* errmsg)
{
	printf("\n***Linha %d: Erro: %s\n", lineno, errmsg);
}

//int yywrap() { return 1; }
	


 
int main(int argc, char** argv){
	//extern yydebug;
//	yydebug=1;
    yyparse();
	PercorreArvore(arvore,NULL);

//	printf("arvore: %d \n",(*arvore).teste);
//	mng_prg p = 	(*arvore).prog;
//	printf("arvore2: %d \n",(*arvore).prog.teste);
//	printprg(arvore);
     return 0;
}

