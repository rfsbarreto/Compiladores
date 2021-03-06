#define DEC(dec) mng_##dec dec
#define DECP(dec) mng_##dec* p_##dec
//#include "bib_Tipos.h"
#include "verificacao.h"
//#include "pilha.h"
#include "leitura.h"




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


mng_pars* inicializapars(mng_par *par,mng_pars* pars){
	int tamanho= sizeof(mng_pars);
	DECP(pars) = (mng_pars*) malloc(tamanho);
	(*p_pars).par = par;

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
								
							//	printf("Erro de retorno na linha: %d ", (*(*proximo).cmd).linha);
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















