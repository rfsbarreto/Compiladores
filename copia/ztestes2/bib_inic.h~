#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
#include "bib_Tipos.h"
#include "pilha.h"
/*<<<<<<< HEAD

void Percorredecvar(mng_decvar decvar,lista_simb* tbl);
======= */
void Percorredecvar(mng_decvar* decvar,lista_simb* tbl);
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
void PercorreCmds(mng_cmds*cmds,lista_simb* tbl);
void PercorreCmd(mng_cmd* cmd,lista_simb* tbl);
void PercorreDecvars(mng_decvars * dec,lista_simb* tbl);
void Percorrebl(mng_bloco* bl,lista_simb* tbl);
void PercorrePar(mng_par *par,lista_simb* tbl);
void PercorrePars(mng_pars *pars,lista_simb* tbl);
void PercorreListexp(mng_listexp *listexp,lista_simb* tbl);
void PercorreExp(mng_exp *exp,lista_simb* tbl);
//<<<<<<< HEAD
//void PercorreVar(mng_var var,lista_simb* tbl);
pilha* p1;

//mng_prg* inicializaprog(mng_dec dec,mng_prg* prg){
//=======
void PercorreVar(mng_var *var,lista_simb* tbl);
void PercorreOP(mng_op *op,lista_simb* tbl);
pilha*p1;


mng_prg* inicializaprog(mng_dec* dec,mng_prg* prg){
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	int tamanho= sizeof(mng_prg);
	DECP(prg) = (mng_prg*) malloc(tamanho);
	(*p_prg).dec = dec;
	(*p_prg).prog= prg;
	return p_prg;
}


mng_decfunc* inicializadecfunc(DEC(id),mng_pars * pars, mng_bloco* bloco){
	int tamanho= sizeof(mng_decfunc);
	DECP(decfunc) = (mng_decfunc*) malloc(tamanho);
	(*p_decfunc).id = id;
	(*p_decfunc).pars = pars;
	(*p_decfunc).bloco = bloco;
	return p_decfunc;
}

mng_bloco* inicializabloco(mng_decvars* decvars, mng_cmds* cmds){
	int tamanho= sizeof(mng_bloco);
	DECP(bloco) = (mng_bloco*) malloc(tamanho);
	(*p_bloco).decvars = decvars;
	(*p_bloco).cmds = cmds;
	return p_bloco;
}

mng_listnom* inicializalistnom(DEC(id),mng_listnom* listnom){
	int tamanho= sizeof(mng_listnom);
	DECP(listnom) = (mng_listnom*) malloc(tamanho);
	(*p_listnom).id = id;
	(*p_listnom).list= listnom;
	return p_listnom;
}

/*<<<<<<< HEAD
mng_pars* inicializapars(mng_par* par,mng_pars* pars){
	int tamanho= sizeof(mng_pars);
	DECP(pars) = (mng_pars*) malloc(tamanho);
	(*p_pars).par = par;
if 	(pars==NULL) printf ("AKI");
=======*/
mng_pars* inicializapars(mng_par *par,mng_pars* pars){
	int tamanho= sizeof(mng_pars);
	DECP(pars) = (mng_pars*) malloc(tamanho);
	(*p_pars).par = par;
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	(*p_pars).pars= pars;
	return p_pars;
}

mng_par* inicializapar(mng_tip * tip,mng_id id){
	int tamanho= sizeof(mng_par);
	DECP(par) = (mng_par*) malloc(tamanho);
	(*p_par).tip = tip;
	(*p_par).id = id;
	return p_par;
}


mng_var* inicializavar(mng_exp* exp){
	int tamanho= sizeof(mng_var);
	DECP(var) = (mng_var*) malloc(tamanho);
	(*p_var).exp = exp;
	return p_var;
}

mng_decvar* inicializadecvar(mng_tip * tip,DECP(listnom)){
	int tamanho= sizeof(mng_decvar);
	DECP(decvar) = (mng_decvar*) malloc(tamanho);
	(*p_decvar).tip = tip;
	(*p_decvar).p_listnom= p_listnom;
	return p_decvar;
}

mng_decvars * inicializadecvars(mng_decvar* decvar,mng_decvars* decvars){
	int tamanho= sizeof(mng_decvars);
	DECP(decvars) = (mng_decvars*) malloc(tamanho);
	(*p_decvars).decvar = (decvar);
	(*p_decvars).decvars= decvars;
	return p_decvars;
}

mng_cmds * inicializacmds(mng_cmd *cmd,mng_cmds* cmds){
	int tamanho= sizeof(mng_cmds);
	DECP(cmds) = (mng_cmds*) malloc(tamanho);
	(*p_cmds).cmd = cmd;
	(*p_cmds).cmds= cmds;
	return p_cmds;

}

mng_dec* inicializadec(){
	int tamanho= sizeof(mng_dec);
	DECP(dec) = (mng_dec*) malloc(tamanho);
	return p_dec;
}


mng_tip* inicializatipo(){
	int tamanho= sizeof(mng_tip);
	DECP(tip) = (mng_tip*) malloc(tamanho);
	return (p_tip);
}


mng_ptelse * inicializaptelse(mng_cmd* cmd){
	int tamanho= sizeof(mng_ptelse);
	DECP(ptelse) = (mng_ptelse*) malloc(tamanho);
	(*p_ptelse).cmd = cmd;
	return p_ptelse;
}

mng_cmd* inicializacmd(tipo_no tipocmd){
	int tamanho= sizeof(mng_cmd);
	DECP(cmd) = (mng_cmd*) malloc(tamanho);
	(*p_cmd).tipocmd = tipocmd;
	return p_cmd;
}

mng_atrib* inicializaatrib(mng_var* var,mng_exp* exp){
	int tamanho= sizeof(mng_atrib);
	DECP(atrib) = (mng_atrib*) malloc(tamanho);
	(*p_atrib).var = var; 
	(*p_atrib).exp = exp; 
	return p_atrib;
} 

mng_chmet* inicializachmet(DEC(id), mng_listexp * listexp){
	int tamanho= sizeof(mng_chmet);
	DECP(chmet) = (mng_chmet*) malloc(tamanho);
	(*p_chmet).id = id;
	(*p_chmet).listexp = listexp;
	return (p_chmet);
}
mng_listexp * inicializalistexp(mng_exp *exp, mng_listexp* listexp){
	int tamanho= sizeof(mng_listexp);
	DECP(listexp) = (mng_listexp*) malloc(tamanho);
	(*p_listexp).exp = exp;
	(*p_listexp).listexp = listexp;

	
	return p_listexp;
}

mng_exp* inicializaexp(tipo_no tipoexp){
	int tamanho= sizeof(mng_exp);
	DECP(exp) = (mng_exp*) malloc(tamanho);
	(*p_exp).tipoexp = tipoexp;

	return p_exp;
}
mng_tipbase verificatipoexpOP(mng_exp*exp1, mng_exp* exp2){
	
	mng_tipbase tip;
	int tamanho= sizeof(mng_tipbase);
	tip = (mng_tipbase) malloc(tamanho);
	if (exp1!=NULL && exp1!=NULL){	
	if ((*(*exp1).tipo).tipbase == TIPO_FLOAT == (*(*exp2).tipo).tipbase
			|| (*(*exp1).tipo).tipbase == TIPO_FLOAT && TIPO_INT== (*(*exp2).tipo).tipbase
			|| (*(*exp1).tipo).tipbase == TIPO_INT && TIPO_FLOAT== (*(*exp2).tipo).tipbase)
			{ tip = TIPO_FLOAT;}
			if ((*(*exp1).tipo).tipbase == TIPO_INT == (*(*exp2).tipo).tipbase
			|| (*(*exp1).tipo).tipbase == TIPO_CHAR && TIPO_INT== (*(*exp2).tipo).tipbase
			|| (*(*exp1).tipo).tipbase == TIPO_INT && TIPO_CHAR== (*(*exp2).tipo).tipbase)
			{tip = TIPO_INT;}
	}
	return tip;
}

mng_op* inicializaop(mng_exp* exp1,mng_operadores op,mng_exp* exp2){
	int tamanho= sizeof(mng_op);
	DECP(op) = (mng_op*) malloc(tamanho);
	tamanho= sizeof(mng_exp);
	(*p_op).exp1 = (mng_exp*) malloc(tamanho);
	(*p_op).exp1 = exp1;
	(*p_op).exp2 = (mng_exp*) malloc(tamanho);
	(*p_op).exp2 = exp2;
	(*p_op).op = op;

	return p_op;
}


void verificaReturn(mng_bloco *bloco, mng_tip *tip, mng_id id){
		
		mng_cmds * proximo= (*bloco).cmds;
		while(proximo !=NULL){
			if((*(*proximo).cmd).tipocmd == MNG_RETURN){
				
					if((*(*proximo).cmd).ret.tipret == RET_EXP && (*tip).tipbase == TIPO_VAZIO){
						printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
						exit(0);
					}	
					if((*(*proximo).cmd).ret.tipret == RET_EXP){

						if((((*tip).tipbase == TIPO_INT) && ((*(*(*(*proximo).cmd).ret.exp).tipo).tipbase == TIPO_STRING))
						|| (((*tip).tipbase == TIPO_FLOAT) && ((*(*(*(*proximo).cmd).ret.exp).tipo).tipbase == TIPO_STRING))
						){
							printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
							exit(0);
						}
						if(((*tip).tipbase == TIPO_CHAR) 
						&& ((*tip).qtdACOL>1 || (*tip).qtdACOL==0) 
						&& ((*(*(*(*proximo).cmd).ret.exp).tipo).tipbase == TIPO_STRING || (*(*(*(*proximo).cmd).ret.exp).tipo).tipbase == TIPO_CHAR)
						){
							printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
							exit(0);
						}
						
						
						if ((*(*(*proximo).cmd).ret.exp).tipoexp == MNG_VAR)
							/*
							if((tip.qtdACOL != (*proximo).cmd.ret.exp.var.qtdACOL)){
								
								printf("Erro de retorno na linha: %d ", (*proximo).cmd.linha);
								exit(0);
							}*/
							
							if(((*tip).qtdACOL > 0 && (*(*(*(*proximo).cmd).ret.exp).var).qtdACOL > 0)){
								
								printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
								exit(0);
							}
						if ((*tip).qtdACOL > 0  && (*(*(*proximo).cmd).ret.exp).tipoexp != MNG_VAR){
								printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
								exit(0);
							}	
							
					}
				if((*(*proximo).cmd).ret.tipret == RET_VAZIO){
					if(((*tip).tipbase == 0) || ((*tip).tipbase == 3) || (*tip).tipbase == TIPO_CHAR || (*tip).tipbase == TIPO_STRING){
						printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
						exit(0);
					}			
				} 
			} proximo = (*proximo).cmds;
		}
	}



void PercorrePar(mng_par *par,lista_simb* tbl){
	if(par!=NULL){

		tbl=adicionaVar1( tbl ,(*par).id,(*par).tip  );	
	}
}
	
void PercorrePars(mng_pars* pars,lista_simb* tbl){
	mng_pars * p = pars;
	while(p != NULL){
/*<<<<<<< HEAD
printf("percorre pars\n");		
		printf("\ntip par: %d", (*(*p).par).tip.tipbase );
		printf("\nnome id par: %s \n", (*(*p).par).id.name) ;
		PercorrePar((*p).par,tbl);
		PercorrePars((*p).pars,tbl);
	if 	((*p).pars!=NULL)	
		p = (*p).pars;
		else break;
=======*/

		PercorrePar((*p).par, tbl);
		PercorrePars((*p).pars,tbl);
		if ((*p).pars != NULL){
			p = (*p).pars;
		}else break;
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	}
}

void Percorredecvar(mng_decvar* decvar,lista_simb* tbl){
	
	mng_listnom *declistnom = (*decvar).p_listnom;
	while(declistnom != NULL){
		
//<<<<<<< HEAD
				tipo_no t=MNG_DECVAR;
//		verificasimbolo(tbl,(*declistnom).id);//,t);
		verificasimbolo(tbl,(*declistnom).id,t);
		adicionaVar1( tbl ,(*declistnom).id,(*decvar).tip  );
		declistnom = (*declistnom).list;			
/*=======
		if((*declistnom).list !=NULL){
			adicionaVar1( tbl ,(*declistnom).id,(*decvar).tip );
			declistnom = (*declistnom).list;			
		}else break;
>>>>>>> d62241ab7d645bf42c6822837112564b7effa506*/
	}
	imprimirlista(tbl);
	
}

void Percorrebl(mng_bloco* bl,lista_simb* tbl){
	
	mng_bloco * aux= bl;
	if (aux!=NULL){
		if ((*aux).decvars!=NULL)
			PercorreDecvars((*aux).decvars,tbl);

		if ((*aux).cmds!=NULL)
			PercorreCmds((*aux).cmds,tbl);
/*<<<<<<< HEAD
	}else{printf("Enasdasdasdad \n");}
======= */
	}
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	
}

void PercorreDecvars(mng_decvars * dec,lista_simb* tbl){
	mng_decvars * decvars = dec;
	while(decvars !=NULL){
		Percorredecvar((*decvars).decvar, tbl);
		if((*decvars).decvars != NULL){
			decvars = (*decvars).decvars;
		}else break;
	
	}
}

void PercorreCmds(mng_cmds*cmds,lista_simb* tbl){

	mng_cmds * atual = cmds;
	while(atual!=NULL){
	
		PercorreCmd((*atual).cmd, tbl);
		if((*atual).cmds != NULL){
			atual = (*atual).cmds;	}else break;
	}

}

void PercorreListexp(mng_listexp *listexp,lista_simb* tbl){
	if(listexp != NULL){
		PercorreExp((*listexp).exp,tbl);
		PercorreListexp((*listexp).listexp,tbl);
	}
}
void PercorreExp(mng_exp *exp,lista_simb* tbl){


	if((*exp).tipoexp == MNG_TIPBASE){
	
	}
	if((*exp).tipoexp == MNG_VAR){
		tipo_no t = MNG_VAR;
		//(*exp).tip = verificavar(tbl,(*(*exp).var).id,t);		
		verificasimbolo(tbl,(*(*exp).var).id,t);

		//imprimetipbase((*(*exp).tip).tipbase);
		PercorreVar((*exp).var,tbl);	
	}
	if((*exp).tipoexp == MNG_EXP){
	
		PercorreExp((*exp).tipexp.exp,tbl);
	struct mng_exp* exp;//DEC(exp);
	}
	if((*exp).tipoexp == MNG_CHMET){
		
		PercorreListexp((*(*exp).chmet).listexp,tbl);

	}
	if((*exp).tipoexp == MNG_TIPEXP){
		PercorreExp((*exp).exp,tbl);
	}
	if((*exp).tipoexp == MNG_OP){
		PercorreOP((*exp).op,tbl);
	}
	if((*exp).tipoexp == MNG_NAO){
		
		PercorreExp((*exp).nao.exp,tbl);		
		if((*(*exp).tipo).tipbase == TIPO_FLOAT
		|| (*(*exp).tipo).tipbase == TIPO_STRING
		|| (*(*exp).tipo).tipbase == TIPO_VAZIO){
		
		}
	}
}

void PercorreOP(mng_op *op,lista_simb* tbl){

	PercorreExp((*op).exp1,tbl);

	PercorreExp((*op).exp2,tbl);
}

void PercorreVar(mng_var *var,lista_simb* tbl){
	if(var != NULL){
	
		if ((*var).exp != NULL){
			PercorreExp((*var).exp,tbl);
		}
	
	}
}



void PercorreCmd(mng_cmd* cmd,lista_simb* tbl){
//<<<<<<< HEAD
//	printf("\n\n\n\n Comandos %u  \n",cmd);
/*	mng_cmd* aux = cmd;
	if((*aux).tipocmd == MNG_IF){

		printf("if");
	}
	if((*aux).tipocmd == MNG_WHILE){
		printf("MNG_WHILE");

		PercorreExp(&(*aux).decwhile.exp,tbl);
=======*/
	//printf("\n Comando   \n");
	//tipo_no t;
	mng_cmd* aux = cmd;
	if((*aux).tipocmd == MNG_IF){
		PercorreExp((*aux).decif.exp,tbl);
		PercorreCmd((*aux).decif.cmd,tbl); 
		if((*aux).decif.ptelse != NULL)
		if((*(*aux).decif.ptelse).cmd != NULL){
			PercorreCmd((*(*aux).decif.ptelse).cmd,tbl);
		}

	}
	if((*aux).tipocmd == MNG_WHILE){

		PercorreExp((*aux).decwhile.exp,tbl);
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
		if ((*aux).decwhile.cmd!=NULL){
			PercorreCmd((*aux).decwhile.cmd,tbl);
		}	



	}
	if((*aux).tipocmd == MNG_ATRIB){
		//PercorreVar(cmd.atrib.var);
/*<<<<<<< HEAD
		printf("ATRIB\n");
		PercorreExp(&(*aux).atrib.exp,tbl);

	}
	if((*aux).tipocmd == MNG_BLOCO){
//		printf("percorre bloco dentro do cmd\n");
				Percorrebl((*aux).bloco,tbl);
		printf("MNG_BLOCO");
=======*/

		tipo_no t=MNG_VAR;

		verificasimbolo(tbl,(*(*(*aux).atrib).var).id,t);
//		verificasimbolo(tbl,(*(*aux).atrib.var).id);
		PercorreExp((*(*aux).atrib).exp,tbl);
	}
	if((*aux).tipocmd == MNG_RETURN){
		if ((*aux).ret.tipret == RET_EXP){

			PercorreExp((*aux).ret.exp,tbl);
		}
	}
	if((*aux).tipocmd == MNG_CHMET){
	
		tipo_no t=MNG_CHMET;
		verificasimbolo(tbl,(*(*aux).chmet).id,t);
		PercorreListexp((*(*aux).chmet).listexp,tbl);
		
	}
	if((*aux).tipocmd == MNG_BLOCO){
		//printf("\npercorre bloco dentro do cmd\n");
		//tipo_no t=MNG_BLOCO;
		//erificasimbolo(tbl,(*(*aux).chmet).id,t);
		Percorrebl((*aux).bloco,tbl);
		
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	}

}
void PercorreArvore(mng_prg* arvore,lista_simb* tbl){
	if(arvore != NULL){
		lista_simb* tabela;		
		if (tbl==NULL){
			tabela=	(lista_simb*) malloc(sizeof(lista_simb));
			p1=(pilha*) malloc(sizeof(pilha));
		}else
			tabela=tbl;
		
		if ((*(*arvore).dec).tipodec == MNG_DECVAR){
			//decvar
			if((*(*arvore).dec).decvar){
				Percorredecvar((*(*arvore).dec).decvar, tabela);
			}
		}else{
//<<<<<<< HEAD
/*			verificasimbolo(tbl,(*arvore).dec.decfunc.id);
			lista_simb* tblfunc= (lista_simb*) malloc(sizeof(lista_simb));
			printf("\ntipo decfunc %d", (*arvore).dec.decfunc.tip);			
			printf("\n  id %s  \n", (*arvore).dec.decfunc.id.name);	
			PercorrePars((*arvore).dec.decfunc.pars,tblfunc);
			//imprimirlista(tblfunc);							
			Percorrebl(&((*arvore).dec.decfunc.bloco),tblfunc);	
			printf("Imprimindo lista da funcao: ");imprimirlista(tblfunc);								
			adicionaFunc(tabela, (*arvore).dec.decfunc,tblfunc);*/
//=======
			if((*(*arvore).dec).decfunc != NULL){
				tipo_no t=MNG_DECFUNC;
				verificasimbolo(tbl,(*(*(*arvore).dec).decfunc).id,t);
//				verificasimbolo(tbl,(*(*(*arvore).dec).decfunc).id);//,t);
				lista_simb* tblfunc= (lista_simb*) malloc(sizeof(lista_simb));
				
				PercorrePars((*(*(*arvore).dec).decfunc).pars, tblfunc);
				Percorrebl((*(*(*arvore).dec).decfunc).bloco,tblfunc);		
						
			
				adicionaFunc(tabela, (*(*arvore).dec).decfunc,tblfunc);
			

			}
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
			
		}

		if((*arvore).prog != NULL){
			PercorreArvore((*arvore).prog,tabela);
//<<<<<<< HEAD
		}
		else{					imprimirlista(tabela);				}
	}
//	imprimirlista(tabela);	
//=======
/*		}else{
				printf("Imprimindo lista FINAL: ");
				imprimirlista(tabela);

		}
	}
>>>>>>> d62241ab7d645bf42c6822837112564b7effa506*/
}



