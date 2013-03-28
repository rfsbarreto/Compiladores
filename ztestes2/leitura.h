void Percorredecvar(mng_decvar* decvar,lista_simb* tbl);
void PercorreCmds(mng_cmds*cmds,lista_simb* tbl);
void PercorreCmd(mng_cmd* cmd,lista_simb* tbl);
void PercorreDecvars(mng_decvars * dec,lista_simb* tbl);
void Percorrebl(mng_bloco* bl,lista_simb* tbl);
void PercorrePar(mng_par *par,lista_simb* tbl);
void PercorrePars(mng_pars *pars,lista_simb* tbl);
void PercorreListexp(mng_listexp *listexp,lista_simb* tbl);
void PercorreExp(mng_exp *exp,lista_simb* tbl);
void PercorreVar(mng_var *var,lista_simb* tbl);
void PercorreOP(mng_op *op,lista_simb* tbl);


void PercorrePar(mng_par *par,lista_simb* tbl){
	if(par!=NULL){
		//printf("\ntip par: %d", (*par).tip);
	///	printf("\nnome id par: %s", (*par).id.name);
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
	//	printf("percorre pars\n");		
	//	printf("\ntip par: %d", (*(*(*p).par).tip).tipbase );
	///	printf("\nnome id par: %s \n", (*(*p).par).id.name) ;
		printf("Percorrendo Parametros"); //nome id par: %s \n", (*(*p).par).id.name) ;
		PercorrePar((*p).par, tbl);
		PercorrePars((*p).pars,tbl);
		if ((*p).pars != NULL){
			p = (*p).pars;
		}else break;
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	}
}

void Percorredecvar(mng_decvar* decvar,lista_simb* tbl){
	printf("Percorrendo var\n");//"\ntipo decvar %d", (*decvar).tip);
	mng_listnom *declistnom = (*decvar).p_listnom;
	while(declistnom != NULL){
	//	printf("\n  id %s ", (*declistnom).id.name);
//<<<<<<< HEAD
				tipo_no t=MNG_DECVAR;
//		verificasimbolo(tbl,(*declistnom).id);//,t);
		verificasimbolo(tbl,(*declistnom).id,t);
		adicionaVar1( tbl ,(*declistnom).id,(*decvar).tip  );
		declistnom = (*declistnom).list;			

	}
	//imprimirlista(tbl);
	//return tbl;
}

void Percorrebl(mng_bloco* bl,lista_simb* tbl){
	//printf("abre bloco\n");
	mng_bloco * aux= bl;
	if (aux!=NULL){
				printf("Percorrendo bloco\n"); //nome id par: %s \n", (*(*p).par).id.name) ;
		if ((*aux).decvars!=NULL)
			PercorreDecvars((*aux).decvars,tbl);

		if ((*aux).cmds!=NULL)
			PercorreCmds((*aux).cmds,tbl);
/*<<<<<<< HEAD
	}else{printf("Enasdasdasdad \n");}
======= */
	}//else{printf("\n");}
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	//printf("Encerra bloco \n");
}

void PercorreDecvars(mng_decvars * dec,lista_simb* tbl){
	mng_decvars * decvars = dec;
	while(decvars !=NULL){
		printf("Percorrendo Decvars\n");
		Percorredecvar((*decvars).decvar, tbl);
		if((*decvars).decvars != NULL){
			decvars = (*decvars).decvars;
		}else break;
	
	}
}

void PercorreCmds(mng_cmds*cmds,lista_simb* tbl){

	mng_cmds * atual = cmds;
	while(atual!=NULL){
		//printf("\ncmds");
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
	///printf("\n tipo da exp %d", (*exp).tipoexp);

	if((*exp).tipoexp == MNG_TIPBASE){
	
		
	
	}
	if((*exp).tipoexp == MNG_VAR){
		tipo_no t = MNG_VAR;
		//(*exp).tip = verificavar(tbl,(*(*exp).var).id,t);		
		verificasimbolo(tbl,(*(*exp).var).id,t);
		
	
//		imprimetipbase((*(*exp).tip).tipbase);
		PercorreVar((*exp).var,tbl);	
	}
	if((*exp).tipoexp == MNG_EXP){
	//	printf("\nqtd de ACOL:%d ",(*(*exp).tipexp.tip).qtdACOL);
		PercorreExp((*exp).tipexp.exp,tbl);
	struct mng_exp* exp;//DEC(exp);
	}
	if((*exp).tipoexp == MNG_CHMET){
	//	printf("\nnome do metodo: %s", (*(*exp).chmet).id.name);
		PercorreListexp((*(*exp).chmet).listexp,tbl);

	}
	if((*exp).tipoexp == MNG_TIPEXP){
		PercorreExp((*exp).exp,tbl);
	}
	if((*exp).tipoexp == MNG_OP){
		PercorreOP((*exp).op,tbl);
	}
	if((*exp).tipoexp == MNG_NAO){
		//printf("\nNAO");
		PercorreExp((*exp).nao.exp,tbl);		
		if((*(*exp).tipo).tipbase == TIPO_FLOAT
		|| (*(*exp).tipo).tipbase == TIPO_STRING
		|| (*(*exp).tipo).tipbase == TIPO_VAZIO){
			//printf("operação de não com tipo inválido");
		}
	}
}

void PercorreOP(mng_op *op,lista_simb* tbl){
	//printf("\nOperação na linha %d", (*op).linha);
	PercorreExp((*op).exp1,tbl);
	///printf(" Tipo da operação: %d",(*op).op);
	PercorreExp((*op).exp2,tbl);
}

void PercorreVar(mng_var *var,lista_simb* tbl){
	if(var != NULL){
		//printf("\nnome da var:%s ",(*var).id.name);
		if ((*var).exp != NULL){
			PercorreExp((*var).exp,tbl);
		}
		//printf("\nqtd de ACOL:%d ",(*var).qtdACOL);
	}
}



void PercorreCmd(mng_cmd* cmd,lista_simb* tbl){
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
		//printf("\nMNG_WHILE");
		PercorreExp((*aux).decwhile.exp,tbl);

		if ((*aux).decwhile.cmd!=NULL){
			PercorreCmd((*aux).decwhile.cmd,tbl);
		}	



	}
	if((*aux).tipocmd == MNG_ATRIB){
		//PercorreVar(cmd.atrib.var);
		//printf("\nATRIB\n");
		tipo_no t=MNG_VAR;
	//	printf("id: %s",(*(*(*aux).atrib).var).id.name);
		verificasimbolo(tbl,(*(*(*aux).atrib).var).id,t);
//		verificasimbolo(tbl,(*(*aux).atrib.var).id);
		PercorreExp((*(*aux).atrib).exp,tbl);
	}
	if((*aux).tipocmd == MNG_RETURN){
		if ((*aux).ret.tipret == RET_EXP){
		//	printf("\nreturn com exp");
			PercorreExp((*aux).ret.exp,tbl);
		}else{
		//	printf("\nreturn ;");	
		}
	}
	if((*aux).tipocmd == MNG_CHMET){
		//printf("\nchamada ao método id : %s", (*(*aux).chmet).id.name);
		tipo_no t=MNG_CHMET;
		verificasimbolo(tbl,(*(*aux).chmet).id,t);
		PercorreListexp((*(*aux).chmet).listexp,tbl);
		
	}
	if((*aux).tipocmd == MNG_BLOCO){
		//printf("\npercorre bloco dentro do cmd\n");
		//tipo_no t=MNG_BLOCO;
		//erificasimbolo(tbl,(*(*aux).chmet).id,t);
		Percorrebl((*aux).bloco,tbl);
	//	printf("\nMNG_BLOCO");

	}

}

void PercorreArvore(mng_prg* arvore,lista_simb* tbl){
//	printf("Percorrendo árvore: \n");	
	if(arvore != NULL){

		lista_simb* tabela;		
		if (tbl==NULL){
			tabela=	(lista_simb*) malloc(sizeof(lista_simb));
		//	p1=(pilha*) malloc(sizeof(pilha));
		}else
			tabela=tbl;
		//printf("\ntipo no dec : %d ", (*(*arvore).dec).tipodec);
		if ((*(*arvore).dec).tipodec == MNG_DECVAR){
			//decvar
		printf("Percorrendo árvore( decvar): \n");	
			if((*(*arvore).dec).decvar){
				Percorredecvar((*(*arvore).dec).decvar, tabela);
			}
		}else{
			if((*(*arvore).dec).decfunc != NULL){
				printf("Percorrendo árvore( decfunc): \n");	
				tipo_no t=MNG_DECFUNC;
				verificasimbolo(tbl,(*(*(*arvore).dec).decfunc).id,t);
//				verificasimbolo(tbl,(*(*(*arvore).dec).decfunc).id);//,t);
				lista_simb* tblfunc= (lista_simb*) malloc(sizeof(lista_simb));
			//	printf("\ntipo decfunc", (*(*(*arvore).dec).decfunc).tip);			
				//printf("\n  id %s", (*(*(*arvore).dec).decfunc).id.name);	
				PercorrePars((*(*(*arvore).dec).decfunc).pars, tblfunc);
				Percorrebl((*(*(*arvore).dec).decfunc).bloco,tblfunc);		
			//	printf("Imprimindo lista da funcao: ");imprimirlista(tblfunc);			
				//printf("decfunc analisada: \n");	
				adicionaFunc(tabela, (*(*arvore).dec).decfunc,tblfunc);
			

			}

			
		}

		if((*arvore).prog != NULL){
			imprimirlista(tabela);
			PercorreArvore((*arvore).prog,tabela);
		}
		else{					printf("Imprimindo lista FINAL: ");imprimirlista(tabela);				}
	}
	printf("arvore vazia");//imprimirlista(tabela);	
}

