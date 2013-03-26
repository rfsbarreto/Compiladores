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

mng_par* inicializapar(DEC(tip),mng_id id){
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

mng_decvar* inicializadecvar(DEC(tip),DECP(listnom)){
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

mng_tip inicializatipo(){
	int tamanho= sizeof(mng_tip);
	DECP(tip) = (mng_tip*) malloc(tamanho);
	return *p_tip;
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
mng_tipbase verificatipoexpOP(mng_op* op){
	mng_tipbase tip;

	if((*op).op == OP_SUB || (*op).op == OP_SOMA || (*op).op == OP_DIV || (*op).op == OP_MULT){
		if ((*(*op).exp1).tipoexp == MNG_VAR && (*(*op).exp2).tipoexp == MNG_VAR){
			
			if ((*(*(*op).exp1).var).qtdACOL != (*(*(*op).exp2).var).qtdACOL){
					printf("Erro, operação com tipos incompatíveis,  na linha: %d ", (*op).linha);
					exit(0);
			}
		}
		if(((*(*op).exp1).tipo.tipbase==TIPO_INT && (*(*op).exp2).tipo.tipbase==TIPO_INT)
		|| ((*(*op).exp1).tipo.tipbase==TIPO_INT && (*(*op).exp2).tipo.tipbase==TIPO_CHAR)
		|| ((*(*op).exp1).tipo.tipbase==TIPO_CHAR && (*(*op).exp2).tipo.tipbase==TIPO_INT)
		) {
				tip = TIPO_INT;
				
		}else {
			if(((*(*op).exp1).tipo.tipbase==TIPO_FLOAT && (*(*op).exp2).tipo.tipbase==TIPO_FLOAT) 
			|| ((*(*op).exp1).tipo.tipbase==TIPO_FLOAT && (*(*op).exp2).tipo.tipbase==TIPO_INT)
			|| ((*(*op).exp1).tipo.tipbase==TIPO_INT && (*(*op).exp2).tipo.tipbase==TIPO_FLOAT))
			{
				tip = TIPO_FLOAT;
			
			}else{ 
				printf("Erro, operação com tipos incompatíveis,  na linha: %d ", (*op).linha);
				exit(0);
			}
		}
	}else{
		if ((*(*op).exp1).tipoexp == MNG_VAR && (*(*op).exp2).tipoexp == MNG_VAR){
			if ((*(*(*op).exp1).var).qtdACOL != (*(*(*op).exp2).var).qtdACOL){
					printf("Erro, operação com tipos incompatíveis,  na linha: %d ", (*op).linha);
					exit(0);
			}
		}
		if(    ((*(*op).exp1).tipo.tipbase==TIPO_INT && (*(*op).exp2).tipo.tipbase==TIPO_INT) 
			|| ((*(*op).exp1).tipo.tipbase==TIPO_FLOAT && (*(*op).exp2).tipo.tipbase==TIPO_FLOAT) 
			|| ((*(*op).exp1).tipo.tipbase==TIPO_FLOAT && (*(*op).exp2).tipo.tipbase==TIPO_INT)
			|| ((*(*op).exp1).tipo.tipbase==TIPO_INT && (*(*op).exp2).tipo.tipbase==TIPO_FLOAT)){
			
				tip = TIPO_INT;
				
		}else{ 
				printf("Erro, operação com tipos incompatíveis,  na linha: %d ", (*op).linha);
				exit(0);
		}
	}
	return tip;
}

mng_op* inicializaop(mng_exp* exp1,mng_operadores op,mng_exp* exp2){
	int tamanho= sizeof(mng_op);
	DECP(op) = (mng_op*) malloc(tamanho);
	(*p_op).exp1 = exp1;
	(*p_op).exp2 = exp2;
	(*p_op).op = op;

	return p_op;
}


void verificaReturn(mng_bloco *bloco, mng_tip tip, mng_id id){
		
		mng_cmds * proximo= (*bloco).cmds;
		while(proximo !=NULL){
			if((*(*proximo).cmd).tipocmd == MNG_RETURN){
				
					if((*(*proximo).cmd).ret.tipret == RET_EXP && tip.tipbase == TIPO_VAZIO){
						printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
						exit(0);
					}	
					if((*(*proximo).cmd).ret.tipret == RET_EXP){

						if(((tip.tipbase == TIPO_INT) && ((*(*(*proximo).cmd).ret.exp).tipo.tipbase == TIPO_STRING))
						|| ((tip.tipbase == TIPO_FLOAT) && ((*(*(*proximo).cmd).ret.exp).tipo.tipbase == TIPO_STRING))
						){
							printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
							exit(0);
						}
						if((tip.tipbase == TIPO_CHAR) 
						&& (tip.qtdACOL>1 || tip.qtdACOL==0) 
						&& ((*(*(*proximo).cmd).ret.exp).tipo.tipbase == TIPO_STRING || (*(*(*proximo).cmd).ret.exp).tipo.tipbase == TIPO_CHAR)
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
							
							if((tip.qtdACOL > 0 && (*(*(*(*proximo).cmd).ret.exp).var).qtdACOL > 0)){
								
								printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
								exit(0);
							}
						if (tip.qtdACOL > 0  && (*(*(*proximo).cmd).ret.exp).tipoexp != MNG_VAR){
								printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
								exit(0);
							}	
							
					}
				if((*(*proximo).cmd).ret.tipret == RET_VAZIO){
					if((tip.tipbase == 0) || (tip.tipbase == 3) || tip.tipbase == TIPO_CHAR || tip.tipbase == TIPO_STRING){
						printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
						exit(0);
					}			
				} 
			} proximo = (*proximo).cmds;
		}
	}



void PercorrePar(mng_par *par,lista_simb* tbl){
	if(par!=NULL){
		printf("\ntip par: %d", (*par).tip);
		printf("\nnome id par: %s", (*par).id.name);
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
		printf("percorre pars\n");		
		printf("\ntip par: %d", (*(*p).par).tip.tipbase );
		printf("\nnome id par: %s \n", (*(*p).par).id.name) ;
		PercorrePar((*p).par, tbl);
		PercorrePars((*p).pars,tbl);
		if ((*p).pars != NULL){
			p = (*p).pars;
		}else break;
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	}
}

void Percorredecvar(mng_decvar* decvar,lista_simb* tbl){
	printf("\ntipo decvar %d", (*decvar).tip);
	mng_listnom *declistnom = (*decvar).p_listnom;
	while(declistnom != NULL){
		printf("\n  id %s ", (*declistnom).id.name);
//<<<<<<< HEAD
		verificasimbolo(tbl,(*declistnom).id);
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
	return tbl;
}

void Percorrebl(mng_bloco* bl,lista_simb* tbl){
	printf("abre bloco\n");
	mng_bloco * aux= bl;
	if (aux!=NULL){
		if ((*aux).decvars!=NULL)
			PercorreDecvars((*aux).decvars,tbl);

		if ((*aux).cmds!=NULL)
			PercorreCmds((*aux).cmds,tbl);
/*<<<<<<< HEAD
	}else{printf("Enasdasdasdad \n");}
======= */
	}else{printf("\n");}
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	printf("Encerra bloco \n");
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
		printf("\ncmds");

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
	printf("\n tipo da exp %d", (*exp).tipoexp);

	if((*exp).tipoexp == MNG_TIPBASE){
		printf("\ntipobase: %d ",(*exp).tipo.tipbase); 
		if ((*exp).tipo.tipbase == TIPO_STRING)
			printf(" valor1: %c ",(*exp).string.valor);
		if ((*exp).tipo.tipbase == TIPO_CHAR)
			printf(" valorstring: %s ",(*exp).string);
		if ((*exp).tipo.tipbase == TIPO_INT)
			printf(" valor1: %d ",(*exp).numint.valor);
		if ((*exp).tipo.tipbase == TIPO_FLOAT)
			printf(" valor1: %f ",(*exp).numfloat.valor);
	}
	if((*exp).tipoexp == MNG_VAR){
		PercorreVar((*exp).var,tbl);	
	}
	if((*exp).tipoexp == MNG_EXP){
		printf("\nqtd de ACOL:%d ",(*(*exp).tipexp.tip).qtdACOL);
		PercorreExp((*exp).tipexp.exp,tbl);
	struct mng_exp* exp;//DEC(exp);
	}
	if((*exp).tipoexp == MNG_CHMET){
		printf("\nnome do metodo: %s", (*(*exp).chmet).id.name);
		PercorreListexp((*(*exp).chmet).listexp,tbl);

	}
	if((*exp).tipoexp == MNG_TIPEXP){
		PercorreExp((*exp).exp,tbl);
	}
	if((*exp).tipoexp == MNG_OP){
		PercorreOP((*exp).op,tbl);
	}
	if((*exp).tipoexp == MNG_NAO){
		printf("\nNAO");
		PercorreExp((*exp).nao.exp,tbl);		
		if((*exp).tipo.tipbase == TIPO_FLOAT
		|| (*exp).tipo.tipbase == TIPO_STRING
		|| (*exp).tipo.tipbase == TIPO_VAZIO){
			printf("operação de não com tipo inválido");
		}
	}
}

void PercorreOP(mng_op *op,lista_simb* tbl){
	printf("\nOperação na linha %d", (*op).linha);
	PercorreExp((*op).exp1,tbl);
	printf(" Tipo da operação: %d",(*op).op);
	PercorreExp((*op).exp2,tbl);
}

void PercorreVar(mng_var *var,lista_simb* tbl){
	if(var != NULL){
		printf("\nnome da var:%s ",(*var).id.name);
		if ((*var).exp != NULL){
			PercorreExp((*var).exp,tbl);
		}
		printf("\nqtd de ACOL:%d ",(*var).qtdACOL);
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
		printf("\nMNG_WHILE");
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
		printf("\nATRIB\n");
		PercorreExp((*aux).atrib.exp,tbl);
	}
	if((*aux).tipocmd == MNG_RETURN){
		if ((*aux).ret.tipret == RET_EXP){
			printf("\nreturn com exp");
			PercorreExp((*aux).ret.exp,tbl);
		}else{
			printf("\nreturn ;");	
		}
	}
	if((*aux).tipocmd == MNG_CHMET){
		printf("\nchamada ao método id : %s", (*(*aux).chmet).id.name);
		PercorreListexp((*(*aux).chmet).listexp,tbl);
	}
	if((*aux).tipocmd == MNG_BLOCO){
		//printf("\npercorre bloco dentro do cmd\n");
		Percorrebl((*aux).bloco,tbl);
		printf("\nMNG_BLOCO");
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
		printf("\ntipo no dec : %d ", (*(*arvore).dec).tipodec);
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
				verificasimbolo(tbl,(*(*(*arvore).dec).decfunc).id);
				lista_simb* tblfunc= (lista_simb*) malloc(sizeof(lista_simb));
				printf("\ntipo decfunc", (*(*(*arvore).dec).decfunc).tip);			
				printf("\n  id %s", (*(*(*arvore).dec).decfunc).id.name);	
				PercorrePars((*(*(*arvore).dec).decfunc).pars, tblfunc);
				Percorrebl((*(*(*arvore).dec).decfunc).bloco,tblfunc);		
				printf("Imprimindo lista da funcao: ");imprimirlista(tblfunc);								
				adicionaFunc(tabela, (*(*arvore).dec).decfunc,tblfunc);
			}
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
			
		}

		if((*arvore).prog != NULL){
			PercorreArvore((*arvore).prog,tabela);
//<<<<<<< HEAD
		}
		else{					printf("Imprimindo lista FINAL: ");imprimirlista(tabela);				}
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


