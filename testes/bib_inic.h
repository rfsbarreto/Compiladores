#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
#include "bib_Tipos.h"
#include "pilha.h"
void Percorredecvar(mng_decvar* decvar);
void PercorreCmds(mng_cmds*cmds);
void PercorreCmd(mng_cmd* cmd);
void PercorreDecvars(mng_decvars * dec);
void Percorrebl(mng_bloco* bl);
void PercorrePar(mng_par *par);
void PercorrePars(mng_pars *pars);
void PercorreListexp(mng_listexp *listexp);
void PercorreExp(mng_exp *exp);
void PercorreVar(mng_var *var);
void PercorreOP(mng_op *op);

mng_prg* inicializaprog(mng_dec dec,mng_prg* prg){
	int tamanho= sizeof(mng_prg);
	DECP(prg) = (mng_prg*) malloc(tamanho);
	(*p_prg).dec = dec;
	(*p_prg).prog= prg;
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
	return p_listnom;
}

mng_pars* inicializapars(mng_par *par,mng_pars* pars){
	int tamanho= sizeof(mng_pars);
	DECP(pars) = (mng_pars*) malloc(tamanho);
	(*p_pars).par = par;
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

mng_dec inicializadec(){
	int tamanho= sizeof(mng_dec);
	DECP(dec) = (mng_dec*) malloc(tamanho);
	return *p_dec;
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

mng_chmet inicializachmet(DEC(id), mng_listexp * listexp){
	int tamanho= sizeof(mng_chmet);
	DECP(chmet) = (mng_chmet*) malloc(tamanho);
	(*p_chmet).id = id;
	(*p_chmet).listexp = listexp;
	return (*p_chmet);
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


void verificaReturn(mng_bloco bloco, mng_tip tip, mng_id id){
		
		mng_cmds * proximo= bloco.cmds;
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



void PercorrePar(mng_par *par){
	if(par!=NULL){
		printf("\ntip par: %d", (*par).tip);
		printf("\nnome id par: %s", (*par).id.name);
	}
}
	
void PercorrePars(mng_pars* pars){
	mng_pars * p = pars;
	while(p != NULL){
		PercorrePar((*p).par);
		PercorrePars((*p).pars);
		p = (*p).pars;
	}
}

void Percorredecvar(mng_decvar *decvar){
	printf("\ntipo decvar %d", (*decvar).tip);
	mng_listnom *declistnom = (*decvar).p_listnom;
	while(declistnom != NULL){
		printf("\n  id %s ", (*declistnom).id.name);
		declistnom = (*declistnom).list;			
	}

}

void Percorrebl(mng_bloco* bl){
	printf("percorre bloco\n");
	mng_bloco * aux= bl;
	if (aux!=NULL){
		if ((*aux).decvars!=NULL)
			PercorreDecvars((*aux).decvars);

		if ((*aux).cmds!=NULL)
			PercorreCmds((*aux).cmds);
	}
}

void PercorreDecvars(mng_decvars * dec){
	mng_decvars * decvars = dec;
	while(decvars !=NULL){
		Percorredecvar((*decvars).decvar);
		decvars = (*decvars).decvars;	
	}
}

void PercorreCmds(mng_cmds*cmds){

	mng_cmds * atual = cmds;
	while(atual!=NULL){
		printf("\ncmds");

		PercorreCmd((*atual).cmd);
		atual = (*atual).cmds;	
	}

}

void PercorreListexp(mng_listexp *listexp){
	if(listexp != NULL){
		PercorreExp((*listexp).exp);
		PercorreListexp((*listexp).listexp);
	}
}
void PercorreExp(mng_exp *exp){
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
		PercorreVar((*exp).var);	
	}
	if((*exp).tipoexp == MNG_EXP){
		printf("\nqtd de ACOL:%d ",(*(*exp).tipexp.tip).qtdACOL);
		PercorreExp((*exp).tipexp.exp);
	struct mng_exp* exp;//DEC(exp);
	}
	if((*exp).tipoexp == MNG_CHMET){
		printf("\nnome do metodo: %s", (*exp).chmet.id.name);
		PercorreListexp((*exp).chmet.listexp);

	}
	if((*exp).tipoexp == MNG_TIPEXP){
		PercorreExp((*exp).exp);
	}
	if((*exp).tipoexp == MNG_OP){
		PercorreOP((*exp).op);
	}
	if((*exp).tipoexp == MNG_NAO){
		printf("\nNAO");
		PercorreExp((*exp).nao.exp);		
		if((*exp).tipo.tipbase == TIPO_FLOAT
		|| (*exp).tipo.tipbase == TIPO_STRING
		|| (*exp).tipo.tipbase == TIPO_VAZIO){
			printf("operação de não com tipo inválido");
		}
	}
}

void PercorreOP(mng_op *op){
	printf("\nOperação na linha %d", (*op).linha);
	PercorreExp((*op).exp1);
	printf(" Tipo da operação: %d",(*op).op);
	PercorreExp((*op).exp2);
}

void PercorreVar(mng_var *var){
	if(var != NULL){
		printf("\nnome da var:%s ",(*var).id.name);
		if ((*var).exp != NULL){
			PercorreExp((*var).exp);
		}
		printf("\nqtd de ACOL:%d ",(*var).qtdACOL);
	}
}



void PercorreCmd(mng_cmd* cmd){
	printf("\n Comando   \n");
	mng_cmd* aux = cmd;
	if((*aux).tipocmd == MNG_IF){
		PercorreExp((*aux).decif.exp);
		PercorreCmd((*aux).decif.cmd); 
		if((*(*aux).decif.ptelse).cmd != NULL){
			PercorreCmd((*(*aux).decif.ptelse).cmd);
		}

	}
	if((*aux).tipocmd == MNG_WHILE){
		printf("\nMNG_WHILE");
		PercorreExp((*aux).decwhile.exp);
		if ((*aux).decwhile.cmd!=NULL){
			PercorreCmd((*aux).decwhile.cmd);
		}	



	}
	if((*aux).tipocmd == MNG_ATRIB){
		//PercorreVar(cmd.atrib.var);
		printf("\nATRIB\n");
		PercorreExp((*aux).atrib.exp);
	}
	if((*aux).tipocmd == MNG_RETURN){
		if ((*aux).ret.tipret == RET_EXP){
			printf("\nreturn com exp");
			PercorreExp((*aux).ret.exp);
		}else{
			printf("\nreturn ;");	
		}
	}
	if((*aux).tipocmd == MNG_CHMET){
		printf("\nchamada ao método id : %s", (*aux).chmet.id.name);
		PercorreListexp((*aux).chmet.listexp);
	}
	if((*aux).tipocmd == MNG_BLOCO){
		//printf("\npercorre bloco dentro do cmd\n");
		Percorrebl((*aux).bloco);
		printf("\nMNG_BLOCO");
	}

}
void PercorreArvore(mng_prg* arvore){
	if(arvore != NULL){
		printf("\ntipo no dec : %d ", (*arvore).dec.tipodec);
		if ((*arvore).dec.tipodec == MNG_DECVAR){
			//decvar
			Percorredecvar(&(*arvore).dec.decvar);
		}else{
			printf("\ntipo decfunc", (*arvore).dec.decfunc.tip);			
			printf("\n  id %s", (*arvore).dec.decfunc.id.name);	
			PercorrePars((*arvore).dec.decfunc.pars);
			Percorrebl(&((*arvore).dec.decfunc.bloco));		
			
		}

		if((*arvore).prog != NULL){
			PercorreArvore((*arvore).prog);
		}
	}
}


