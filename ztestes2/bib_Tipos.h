#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
#define T(a) case a: printf(#a);break;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {MNG_PROG,MNG_DEC,MNG_DECVAR,MNG_LISTNOM,MNG_TIPO,
MNG_TIPBASE,MNG_DECFUNC,MNG_PARS, MNG_IF, MNG_WHILE,
MNG_ATRIB, MNG_OP, MNG_NAO, MNG_TIPEXP, MNG_RETURN, 
MNG_OPNEG,MNG_PAR,MNG_BLOCO,MNG_DECVARS,MNG_CMD,
MNG_CMDS,MNG_PTELSE,MNG_VAR,MNG_EXP,MNG_CHMET,MNG_LSTEXP} tipo_no;

void imprimetipono(tipo_no t){
switch(t){
T(MNG_PROG)
T(MNG_DEC)
T(MNG_DECVAR)
T(MNG_LISTNOM)
T(MNG_TIPO)
T(MNG_TIPBASE)
T(MNG_DECFUNC)
T(MNG_PARS)
T( MNG_IF)
 T(MNG_WHILE)
T(MNG_ATRIB)
T( MNG_OP)
 T(MNG_NAO)
T(MNG_TIPEXP)
 T(MNG_RETURN)
 T(MNG_OPNEG)
T(MNG_PAR)
T(MNG_BLOCO)
T(MNG_DECVARS)
T(MNG_CMD)
T(MNG_CMDS)
T(MNG_PTELSE)
T(MNG_VAR)
T(MNG_EXP)
T(MNG_CHMET)
T(MNG_LSTEXP)
default:break;
}
}

typedef enum mng_tipbase { 
	TIPO_INT,TIPO_CHAR,TIPO_STRING,TIPO_FLOAT,TIPO_VAZIO
} mng_tipbase ; //tipobase

void imprimetipbase(mng_tipbase t){
switch(t){
T(TIPO_INT)
T(TIPO_CHAR)
T(TIPO_STRING)
T(TIPO_FLOAT)
T(TIPO_VAZIO)
default:break;
}
}

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
	int linha;
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

typedef struct mng_tip{
	int qtdACOL;
	DEC(tipbase);
}mng_tip;



typedef struct mng_var{
	DEC(id);
	struct mng_exp * exp;
	int qtdACOL;
} mng_var;



typedef struct mng_exp{
	tipo_no tipoexp;
	mng_tip tipo;
	union{
		struct mng_tip *tip;
		mng_var *var;//DEC(var);
		struct mng_exp* exp;//DEC(exp);
		mng_chmet * chmet;		
//		DEC(chmet);
		DEC(nao);
		struct mng_op* op;//DEC(op);
		DEC(tipexp);
		DEC(numint);
		DEC(numfloat);
		DEC(string);
	};
}mng_exp;

typedef struct mng_listexp{
	mng_exp *exp;
	//DEC(exp);
	struct mng_listexp* listexp;
}mng_listexp;


typedef struct mng_op{
	int linha;
	mng_exp* exp1;
	mng_operadores op;
	mng_exp* exp2; 
}mng_op;




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
	mng_decvar* decvar;
	struct mng_decvars* decvars;

} mng_decvars;


typedef struct mng_atrib{
	mng_var *var;
//	DEC(var);
	mng_exp *exp;
} mng_atrib;


typedef struct mng_ptelse{
	struct mng_cmd* cmd;
} mng_ptelse;


typedef struct mng_decif { 
//    char* name;
	mng_exp *exp;
	//DEC(exp);
	struct mng_cmd* cmd;
	mng_ptelse* ptelse;
	
} mng_decif;

typedef struct mng_decwhile { 
	mng_exp * exp;	

	struct mng_cmd* cmd;
	
} mng_decwhile;


typedef struct mng_ret{
	mng_tipret tipret;
	union{
		mng_exp *exp;	
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
		mng_chmet* chmet;
//		DEC(chmet);
	};
} mng_cmd;




typedef struct mng_cmds{
	mng_cmd* cmd;
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
	mng_bloco*bloco;
//	DEC(bloco);
} mng_decfunc ; //decfunção


typedef struct mng_dec{
	tipo_no tipodec;
    union{
	mng_decvar* decvar;
        //DEC(decvar);
	mng_decfunc * decfunc;
        //DEC(decfunc);
    };
} mng_dec; //declaracao


typedef struct mng_prg {
	mng_dec *dec;
//	DEC(dec);
	struct mng_prg* prog; //= NULL;
	int teste;
} mng_prg; //programa


typedef struct simbolo{
        mng_tipbase tipo;
        char* name;
		int linha;

} simbolo;


typedef struct funcao{
        mng_tipbase tipo;
        char* name;
		int linha;
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



lista_simb* adicionaVar(lista_simb* s,mng_listnom* listnom, mng_tip tip){
			printf("adicionavar %s \n",(*listnom).id.name);
        	mng_listnom var = (*listnom);
			lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).simb.name=var.id.name;
        	(*sim).simb.linha=var.id.linha;
        	(*sim).simb.tipo=tip.tipbase;
        	(*sim).tipono=0;
			//printf("simbolo %s %d \n",(*sim).simb.name,(*sim).simb.tipo);
			if (s!=NULL){
				//printf("s not null \n");
				(*sim).prox=(*s).prox;
				(*s).prox=sim;			// cabeça apontará para o nó atual
    		}else{
				//printf("s null \n");
				s= (lista_simb*) malloc(sizeof(lista_simb));            
				(*s).prox=sim;
	}
		while (var.list!=NULL){
			var=(*var.list);			
			sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).simb.name=var.id.name;
        	(*sim).simb.linha=var.id.linha;
        	(*sim).simb.tipo=tip.tipbase;
        	(*sim).tipono=0;
        	(*sim).prox=(*s).prox;   //novo no aponta pra quem a cabeça está apontando
			(*s).prox=sim;			// cabeça apontará para o nó atual
			
        }
		return s;

}

lista_simb* adicionaVar1(lista_simb* s,mng_id id, mng_tip tip){
			printf("adicionavar1 %s \n",id.name);
        	//mng_listnom var = (*listnom);
			lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).simb.name=id.name;
        	(*sim).simb.linha=id.linha;
        	(*sim).simb.tipo=tip.tipbase;
        	(*sim).tipono=0;
			//printf("simbolo %s %d \n",(*sim).simb.name,(*sim).simb.tipo);
			if (s!=NULL){
				//printf("s not null \n");
				(*sim).prox=(*s).prox;
				(*s).prox=sim;			// cabeça apontará para o nó atual
    		}else{
				//printf("s null \n");
				s= (lista_simb*) malloc(sizeof(lista_simb));            
				(*s).prox=sim;
	}
	return s;
}

lista_simb* adicionaVars(lista_simb* s,mng_bloco* bloco){
			//printf("adicionavars  \n");//,(*listnom).id.name);
    		mng_decvars* var = (*bloco).decvars;
		lista_simb* aux=(lista_simb*) malloc(sizeof(lista_simb));//=adicionaVar(s,var.p_listnom,var.tip);
		while(var!=NULL){
			adicionaVar(aux,(*(*var).decvar).p_listnom,(*(*var).decvar).tip);
			var=(*var).decvars;
		}
		return aux;
}

lista_simb* adicionaFunc(lista_simb* s,mng_decfunc* decfunc, lista_simb* saux){
		//printf("adicionafunc %s \n",decfunc.id.name);
        	lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).funcao.name=(*decfunc).id.name;
        	(*sim).funcao.linha=(*decfunc).id.linha;
        	(*sim).funcao.tipo=(*decfunc).tip.tipbase;
        	(*sim).tipono=1;
		(*sim).funcao.lista = saux;
		if (s!=NULL){
	
				(*sim).prox=(*s).prox;
				(*s).prox=sim;			// cabeça apontará para o nó atual
    		}else{

				s= (lista_simb*) malloc(sizeof(lista_simb));            
				(*s).prox=sim;
				if (s==NULL){

				}						

		}
		return s;

}

void imprimirlista(lista_simb* s){
		printf("implista ");
		lista_simb* aux=s;
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;
			//variável
			if ((*aux).tipono == 0){
				printf("\nvar: %s  ",(*aux).simb.name);
				printf("\ntipo2:   ");
				imprimetipbase((*aux).simb.tipo);
			}else{
				printf("\nfunc: %s  ",(*aux).funcao.name);
				printf("\ntipo2:   ");imprimetipbase((*aux).funcao.tipo);
				if((*aux).funcao.lista != NULL){
					imprimirlista((*aux).funcao.lista);
				}
			}
			
 	       }
}


void procuraNome(lista_simb* s, char*nome){
		printf("implista ");
		lista_simb* aux=s;
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;
			//variável
			if ((*aux).tipono == 0){
				printf("\nvar: %s  ",(*aux).simb.name);
				printf("\ntipo: ");imprimetipono((*aux).simb.tipo);
			}else{
				printf("\nfunc: %s  ",(*aux).funcao.name);
				printf("\ntipo: ");imprimetipono((*aux).funcao.tipo);
				if((*aux).funcao.lista != NULL){
					imprimirlista((*aux).funcao.lista);
				}
			}
			
 	       }
}






int isequal(char* s1,char* s2){
		int i=0; int igual=1; 
		char* y=s1; 		char* z=s2;	
		int max=( strlen(s1) <= strlen(s2))?strlen(s2):strlen(s1);	
		for (i=0;i<max;i++ ){
				if (y[i]!=z[i])
					igual=0;
//					printf("essa porra é diferente:   ");
//				printf("erro variável duplicada: %s  ",(*aux).simb.name);
				// exit(0);				
			}
				return igual;
				//if (igual)
				//	exit(0);
}


void verificaIDDuplicado(lista_simb* s, mng_id id){
	
	if(s!=NULL){
//		printf("\nverificando\n");
//		imprimirlista(s);
//		printf("\nverificando\n");
		lista_simb* aux=s;
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;				
				//printf("id: %s  ",(*aux).simb.name);
//				printf("var: %s  \n",id.name);
			//if(strncmp(id.name,(*aux).simb.name),100){
//				if (id.name==(*aux).simb.name)
			//int i=0; int igual=1; char* y=id.name;char* z=(*aux).simb.name;
			//int max=(strlen(id.name) <= strlen((*aux).simb.name)) ?strlen((*aux).simb.name):strlen(id.name);	
			if (isequal(id.name,(*aux).simb.name)){
				printf("Erro na linha: %d",id.linha);
				//yyerror();
				exit(0);					
			}
/*			for (i=0;i<max;i++ ){
				if (y[i]!=z[i])
				igual=0;
//					printf("essa porra é diferente:   ");
//				printf("erro variável duplicada: %s  ",(*aux).simb.name);
				// exit(0);				
			}
				if (igual)
					exit(0);*/
		}
	}
}



void verificasimbolo(lista_simb* s,mng_id id){

	if(s!=NULL){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;
			while ((*aux).prox!=NULL){
				aux=(*aux).prox;				
				if (isequal(id.name,(*aux).simb.name)){
					//printf("linha : %d linha : %d \n",linha,(*aux).simb.linha);			
					if((*aux).simb.linha>=linha)
						linha=(*aux).simb.linha;
//					else
//						linha=(*aux).simb.linha;
					cont++;				
				}			
			}
			if (cont>1){
					printf("Erro na linha : %d \n",linha);
					exit(0);					
			}	
			if (cont==0){
					printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
	}
	
}

void verificasimbolos(lista_simb* s,mng_listnom* listnom){

	if(s!=NULL){
		//int	cont=0;
		mng_listnom* l=listnom;
		while (l!=NULL){
			lista_simb* aux=s;
			verificasimbolo(s,(*l).id);
			l=(*l).list;
		}
	}
}

void verificasimbolosbloco(lista_simb* s,mng_bloco* bloco){

	if(s!=NULL){
		//int	cont=0;
		mng_decvars* var=(*bloco).decvars;
		while(var!=NULL){
			verificasimbolos(s,(*(*var).decvar).p_listnom);
			var=(*var).decvars;
		}
	}
}

