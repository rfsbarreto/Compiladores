#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
#define T(a) case a: return #a;break;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "enum.h"
//#include "verificacao.h"



char* imprimetipono(tipo_no t){
	switch(t){
			T(MNG_PROG) T(MNG_DEC)  T(MNG_DECVAR)  T(MNG_LISTNOM)  T(MNG_TIPO) T(MNG_TIPBASE) T(MNG_DECFUNC) T(MNG_PARS) 
			T( MNG_IF)  T(MNG_WHILE)  T(MNG_ATRIB) T( MNG_OP)  T(MNG_NAO)  T(MNG_TIPEXP)  T(MNG_RETURN)	T(MNG_OPNEG) 
			T(MNG_PAR) T(MNG_BLOCO) T(MNG_DECVARS) T(MNG_CMD) T(MNG_CMDS) T(MNG_PTELSE) T(MNG_VAR) T(MNG_EXP) T(MNG_CHMET) T(MNG_LSTEXP) 
	default:break; }
}



char* imprimetipbase(mng_tipbase t){
	switch(t){ T(TIPO_INT) T(TIPO_CHAR) T(TIPO_STRING) T(TIPO_FLOAT) T(TIPO_VAZIO)  default:break;}
}





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
	mng_tip*tip;
	DEC(id);
	struct mng_exp * exp;
	struct mng_var * var;
	int qtdACOL;
} mng_var;




typedef struct mng_exp{
	tipo_no tipoexp;
	mng_tip* tipo;
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
	int qtdPars;
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
	mng_tip * tip; 
//    DEC(tip);
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
		mng_atrib* atrib;
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
    	mng_tip * tip;
    DEC(id);
} mng_par ; //parametro


typedef struct mng_pars{
	int qtdPars;
	struct mng_par* par;
	struct mng_pars* pars;
} mng_pars; //parametros


typedef struct  mng_decfunc{
	int qtdPars;	
		mng_tip * tip;
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
        mng_tip* tipo;
//       char* name;
//		int linha;
		int qtdPars;
		tipo_no tiposimbolo;
		mng_id id;
} simbolo;


typedef struct funcao{
        mng_tip *tipo;
//        char* name;
//		int linha;
		mng_id id;
		int qtdPars;
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



lista_simb* adicionaVar(lista_simb* s,mng_listnom* listnom, mng_tip* tip){
			//printf("adicionavar %s \n",(*listnom).id.name);
        	mng_listnom var = (*listnom);
		lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).simb.id=var.id;
        	//(*sim).simb.linha=var.id.linha;

	//	(*sim).simb.tipo = (mng_tip*) malloc(sizeof(mng_tip));
        	(*sim).simb.tipo=tip;
		(*sim).simb.tiposimbolo=MNG_VAR;
	
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
        	(*sim).simb.id=var.id;

        	(*sim).simb.tipo=tip;
        	(*sim).tipono=0;
        	(*sim).prox=(*s).prox;   //novo no aponta pra quem a cabeça está apontando
			(*s).prox=sim;			// cabeça apontará para o nó atual
			
        }
		return s;

}

lista_simb* adicionaVar1(lista_simb* s,mng_id id, mng_tip* tip,tipo_no t){
			//printf("adicionavar1 %s %d %d \n",id.name,(*tip).tipbase,(*tip).qtdACOL);
        	//mng_listnom var = (*listnom);
			lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).simb.id=id;
//        	(*sim).simb.linha=id.linha;
		//(*sim).simb.tipo = (mng_tip*) malloc(sizeof(mng_tip));
        	(*sim).simb.tipo=tip;

		(*sim).simb.tiposimbolo=t;
        	(*sim).tipono=0;
		
			//printf("simbolo %s %d \n",(*sim).simb.name,(*sim).simb.tipo);
			if (s!=NULL){
				//printf("s not null \n");
				(*sim).prox=(*s).prox;
				(*s).prox=sim;			// cabeça apontará para o nó atual
    		}else{
				//printf("s null \n");
				(*sim).prox=NULL;
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
//			printf("adicionafunc %s %d %d \n",id.name,tip.tipbase,tip.tipbase);
	//	printf("adicionavar1 %s %d %d \n",(*decfunc).id.name,(*(*decfunc).tip).tipbase,(*(*decfunc).tip).qtdACOL);
        	lista_simb* sim = (lista_simb*) malloc(sizeof(lista_simb));
        	(*sim).funcao.id=(*decfunc).id;
        	(*sim).funcao.tipo=(*decfunc).tip;
		(*sim).funcao.qtdPars=(*decfunc).qtdPars;		
        	(*sim).tipono=1;
		(*sim).funcao.lista = saux;
		if (s!=NULL){
	
				(*sim).prox=(*s).prox;
				(*s).prox=sim;			// cabeça apontará para o nó atual
    		}else{
				(*sim).prox=NULL;
				s= (lista_simb*) malloc(sizeof(lista_simb));            
				(*s).prox=sim;
				if (s==NULL){

				}						

		}
		return s;

}



