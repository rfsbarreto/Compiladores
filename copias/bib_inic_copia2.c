#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
#include "bib_Tipos.h"


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

mng_pars* inicializapars(DEC(par),mng_pars* pars){
	int tamanho= sizeof(mng_pars);
	DECP(pars) = (mng_pars*) malloc(tamanho);
	(*p_pars).par = &par;
	(*p_pars).pars= pars;
	return p_pars;
}

mng_par inicializapar(DEC(tip),mng_id id){
	int tamanho= sizeof(mng_par);
	DECP(par) = (mng_par*) malloc(tamanho);
	(*p_par).tip = tip;
	(*p_par).id = id;
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
	return *p_dec;
}

mng_tip inicializatipo(){
	int tamanho= sizeof(mng_tip);
	DECP(tip) = (mng_tip*) malloc(tamanho);
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
mng_tipbase verificatipoexpOP(mng_op* op){
	mng_tipbase tip;
	printf("Tipo da exp1= %d\n", (*op).exp1.tipo);
	printf("Tipo da exp2= %d\n", (*op).exp2.tipo);
	if((*op).op == OP_SUB || (*op).op == OP_SOMA || (*op).op == OP_DIV || (*op).op == OP_MULT){
		if((*op).exp1.tipo==TIPO_INT && (*op).exp2.tipo==TIPO_INT) {
		tip = TIPO_INT;
		printf("Tipo da op= %d\n", tip);
		}else {
			if(((*op).exp1.tipo==TIPO_FLOAT && (*op).exp2.tipo==TIPO_FLOAT) 
			|| ((*op).exp1.tipo==TIPO_FLOAT && (*op).exp2.tipo==TIPO_INT)
			|| ((*op).exp1.tipo==TIPO_INT && (*op).exp2.tipo==TIPO_FLOAT))
			{
				tip = TIPO_FLOAT;
				printf("Tipo da op= %d", tip);
			}else{ 
				printf("Erro, operação com tipos incompatíveis,  na linha: %d ", (*op).linha);
				exit(0);
			}
		}
	}else{
		if(    ((*op).exp1.tipo==TIPO_INT && (*op).exp2.tipo==TIPO_INT) 
			|| ((*op).exp1.tipo==TIPO_FLOAT && (*op).exp2.tipo==TIPO_FLOAT) 
			|| ((*op).exp1.tipo==TIPO_FLOAT && (*op).exp2.tipo==TIPO_INT)
			|| ((*op).exp1.tipo==TIPO_INT && (*op).exp2.tipo==TIPO_FLOAT)){
			
				tip = TIPO_INT;
				printf("Tipo da op= %d", tip);
		}else{ 
				printf("Erro, operação com tipos incompatíveis,  na linha: %d ", (*op).linha);
				exit(0);
		}
	}
	return tip;
}

mng_op* inicializaop(mng_exp exp1,mng_operadores op,mng_exp exp2){
	int tamanho= sizeof(mng_op);
	DECP(op) = (mng_op*) malloc(tamanho);
	(*p_op).exp1 = exp1;
	(*p_op).exp2 = exp2;
	(*p_op).op = op;

	return p_op;
}


void verificaReturn(mng_bloco bloco, mng_tip tip){
	//printf("Tipo da func= %d\n", tip.tipbase);
	

	if ((bloco.cmds)!=NULL){
		
		//printf("%d ", (*bloco.cmds).cmd.tipocmd);
			
		if((*bloco.cmds).cmd.tipocmd == MNG_RETURN){
			if((*bloco.cmds).cmd.ret.tipret == RET_EXP && tip.tipbase == TIPO_VAZIO){
				printf("Erro 1de retorno  na lha: %d ", (*bloco.cmds).cmd.linha);
				exit(0);
			}	
			if((*bloco.cmds).cmd.ret.tipret == RET_EXP){
				//printf("Tipo do return= %d\n", (*bloco.cmds).cmd.ret.exp.tipo);
				if(((tip.tipbase == TIPO_INT) && ((*bloco.cmds).cmd.ret.exp.tipo == TIPO_STRING))
				|| ((tip.tipbase == TIPO_FLOAT) && ((*bloco.cmds).cmd.ret.exp.tipo == TIPO_STRING))
				){
					printf("Erro 2 de retorno  na string: %d ", (*bloco.cmds).cmd.linha);
					exit(0);
				}
				if((tip.tipbase == TIPO_CHAR) 
				&& (tip.qtdACOL>1 || tip.qtdACOL==0) 
				&& ((*bloco.cmds).cmd.ret.exp.tipo == TIPO_STRING)
				){
					printf("Erro 3 de retorno  na string: %d ", (*bloco.cmds).cmd.linha);
					exit(0);
				}
				if((tip.tipbase == TIPO_CHAR) 
				&& (tip.qtdACOL>1) 
				&& ((*bloco.cmds).cmd.ret.exp.tipo == TIPO_CHAR)
				){
					printf("Erro 3 de retorno esperado uma string ou um array: %d ", (*bloco.cmds).cmd.linha);
					exit(0);
				}	
			}	
			
			if((*bloco.cmds).cmd.ret.tipret == RET_VAZIO){
				//printf("Tipo vazio");
				if((tip.tipbase == 0) || (tip.tipbase == 3) || tip.tipbase == TIPO_CHAR || tip.tipbase == TIPO_STRING){
					printf("Erro de 3retorno na linha: %d ", (*bloco.cmds).cmd.linha);
					exit(0);
				}			
			} 
		}
		
		mng_cmds * proximo= (*bloco.cmds).cmds;
		while(proximo !=NULL){
			if((*proximo).cmd.tipocmd == MNG_RETURN){
				if((*proximo).cmd.tipocmd == MNG_RETURN){
					if((*proximo).cmd.ret.tipret == RET_EXP && tip.tipbase == TIPO_VAZIO){
						printf("Erro d4e retorno  na lha: %d ", (*proximo).cmd.linha);
						exit(0);
					}	
					if((*proximo).cmd.ret.tipret == RET_EXP){
						//printf("Tipo do return= %d\n", (*bloco.cmds).cmd.ret.exp.tipo);
						if(((tip.tipbase == TIPO_INT) && ((*proximo).cmd.ret.exp.tipo == TIPO_STRING))
						|| ((tip.tipbase == TIPO_FLOAT) && ((*proximo).cmd.ret.exp.tipo == TIPO_STRING))
						){
							printf("Erro 5de retorno  na string: %d ", (*proximo).cmd.linha);
							exit(0);
						}
						if((tip.tipbase == TIPO_CHAR) 
						&& (tip.qtdACOL>1 || tip.qtdACOL==0) 
						&& ((*proximo).cmd.ret.exp.tipo == TIPO_STRING)
						){
							printf("Erro 3 de retorno  na string: %d ", (*proximo).cmd.linha);
							exit(0);
						}	
					}		
				}
				
		
				if((*proximo).cmd.ret.tipret == RET_VAZIO){
					//printf("Tipo vazio");
					if((tip.tipbase == 0) || (tip.tipbase == 3) || tip.tipbase == TIPO_CHAR || tip.tipbase == TIPO_STRING){
						printf("Erro 6de retorno na linha: %d ", (*proximo).cmd.linha);
						exit(0);
					}			
				} 
			} proximo = (*proximo).cmds;
		}
	}
}


