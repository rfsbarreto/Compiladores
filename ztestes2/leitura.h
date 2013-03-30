void Percorredecvar(mng_decvar* decvar,lista_simb* tbl);
void PercorreCmds(mng_cmds*cmds,lista_simb* tbl);
void PercorreCmd(mng_cmd* cmd,lista_simb* tbl);
void PercorreDecvars(mng_decvars * dec,lista_simb* tbl);
void Percorrebl(mng_bloco* bl,lista_simb* tbl);
void PercorrePar(mng_par *par,lista_simb* tbl);
void PercorrePars(mng_pars *pars,lista_simb* tbl);
void PercorreListexp(mng_listexp *listexp,lista_simb* tbl,mng_tip* tip);
void PercorreExp(mng_exp *exp,lista_simb* tbl);
void PercorreVar(mng_var *var,lista_simb* tbl);
void PercorreOP(mng_op *op,lista_simb* tbl);
pilha* p1;


void PercorrePar(mng_par *par,lista_simb* tbl){
	if(par!=NULL){
		//printf("\ntip par: %d", (*par).tip);
	///	printf("\nnome id par: %s", (*par).id.name);
		tbl=adicionaVar1( tbl ,(*par).id,(*par).tip ,MNG_PAR );	
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
		printf("Percorrendo Parametros " ); //nome id par: %s \n", (*(*p).par).id.name) ;
		PercorrePar((*p).par, tbl);
		PercorrePars((*p).pars,tbl);
		if ((*p).pars != NULL){
			p = (*p).pars;
		}else break;
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	}
}

void Percorredecvar(mng_decvar* decvar,lista_simb* tbl){
	//printf("Percorrendo decvar\n");//"\ntipo decvar %d", (*decvar).tip);
	mng_listnom *declistnom = (*decvar).p_listnom;
	while(declistnom != NULL){
	//	printf("\n  id %s ", (*declistnom).id.name);
//<<<<<<< HEAD
				tipo_no t=MNG_DECVAR;
//		verificasimbolo(tbl,(*declistnom).id);//,t);
		verificasimbolo(tbl,(*declistnom).id,t);
		adicionaVar1( tbl ,(*declistnom).id,(*decvar).tip ,MNG_DECVAR );
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
		printf("Percorrendo Cmds\n");
	mng_cmds * atual = cmds;
	while(atual!=NULL){
		//printf("\ncmds");
		PercorreCmd((*atual).cmd, tbl);
		if((*atual).cmds != NULL){
			atual = (*atual).cmds;	}else break;
	}

}

void PercorreListexp(mng_listexp *listexp,lista_simb* tbl,mng_tip* tip){
	if(listexp != NULL){
		PercorreExp((*listexp).exp,tbl);
		
		PercorreListexp((*listexp).listexp,tbl,tip);
	}
}
void PercorreExp(mng_exp *exp,lista_simb* tbl){
	//printf("\n tipo da exp %d", (*exp).tipoexp);
	//printf("Percorrendo EXP tipo %s ",imprimetipono((*exp).tipoexp));
	if((*exp).tipoexp == MNG_TIPBASE){
	
		
	
	}
	if((*exp).tipoexp == MNG_VAR){
		tipo_no t = MNG_VAR;
		//(*exp).tip = verificavar(tbl,(*(*exp).var).id,t);		
		printf("mng var : %s ",(*(*exp).var).id.name);
		verificasimbolo(tbl,(*(*exp).var).id,t);
		
		//verificatipo(exp,
		//(*)
		//printf("teste");
	
//		imprimetipbase((*(*exp).tip).tipbase);
		PercorreVar((*exp).var,tbl);	
	}
	if((*exp).tipoexp == MNG_EXP){
	//	printf("\nqtd de ACOL:%d ",(*(*exp).tipexp.tip).qtdACOL);
		PercorreExp((*exp).tipexp.exp,tbl);
	struct mng_exp* exp;//DEC(exp);
	}
	if((*exp).tipoexp == MNG_CHMET){
		printf("metodo: %s \n", (*(*exp).chmet).id.name);
		tipo_no t=MNG_CHMET;
		verificasimbolo(tbl,(*(*exp).chmet).id,t);
		
		pilha * p=p1;
		printf(" tamanho pilha pro while: %d  ",tamanhopilha(p));
		while ((*p).topo!=NULL){
//			verificasimbolo(tbl,(*(*aux).chmet).id,(*(*p).topo).tbl,t);
			printf("Verificando %u!\n",(*(*p).topo).tbl);
			verificachmet((*(*p).topo).tbl,(*exp).chmet,t);
			(*p).topo=(*(*p).topo).ant;

		} 
		PercorreListexp((*(*exp).chmet).listexp,tbl,NULL);

	}
	if((*exp).tipoexp == MNG_TIPEXP){
		PercorreExp((*exp).exp,tbl);
	}
	if((*exp).tipoexp == MNG_OP){
		PercorreOP((*exp).op,tbl);
	//	printf(" fechou OP");
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
	//	printf("FIM EXP \n");
}

void PercorreOP(mng_op *op,lista_simb* tbl){
	
	printf("\nOperação na linha %d ", (*op).linha);
	PercorreExp((*op).exp1,tbl);
	printf(" Tipo da operação: %d ",(*op).op);
	PercorreExp((*op).exp2,tbl);
	printf(" Fechou OP: %d",(*op).op);
}

void PercorreVar(mng_var *var,lista_simb* tbl){
	printf(" Percorrendo Var: %d",var);
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
		printf("\nchamada ao método id : %s \n", (*(*aux).chmet).id.name);
		tipo_no t=MNG_CHMET;
		mng_tip* tip = verificasimbolo(tbl,(*(*aux).chmet).id,t);

		pilha * p=p1;
		printf("pilha %u",p);
	///	printf(" tamanho pilha pro while: %d  ",tamanhopilha(p));
	/*	while ((*p).topo!=NULL){
//			verificasimbolo(tbl,(*(*aux).chmet).id,(*(*p).topo).tbl,t);
		//	printf("Verificando!");
			verificachmet((*(*p).topo).tbl,(*aux).chmet,t);
			(*p).topo=(*(*p).topo).ant;

		} */ 
		PercorreListexp((*(*aux).chmet).listexp,tbl,tip);
		
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
			printf("Endereço tabela %u ",tabela);
			p1=(pilha*) malloc(sizeof(pilha));
			(*p1).topo=NULL;
		}else
			tabela=tbl;
		//printf("\ntipo no dec : %d ", (*(*arvore).dec).tipodec);
		if ((*(*arvore).dec).tipodec == MNG_DECVAR){
			//decvar
		printf("Percorrendo árvore( decvar): \n");	
			if((*(*arvore).dec).decvar){
				printf("Endereço da PILHA e do topo dela: %u %u \n",p1,(*p1).topo);
				Percorredecvar((*(*arvore).dec).decvar, tabela);
			}
		}else{
			if((*(*arvore).dec).decfunc != NULL){
	
				while (tamanhopilha(p1)>1){
					printf("POP!");pop(p1);
				}				
				insert(tabela,p1);
				printf("Percorrendo árvore( decfunc): \n");	
							printf("Endereço tabela %u %u ",tabela,(*tabela).prox);
				printf("Endereço da PILHA e do topo dela: %u %u \n",p1,(*p1).topo);
				tipo_no t=MNG_DECFUNC;
				verificasimbolo(tabela,(*(*(*arvore).dec).decfunc).id,t);
//				verificasimbolo(tbl,(*(*(*arvore).dec).decfunc).id);//,t);
				printf("vamo ver")				;
				lista_simb* tblfunc= (lista_simb*) malloc(sizeof(lista_simb));
			//	printf("\ntipo decfunc", (*(*(*arvore).dec).decfunc).tip);			
				//printf("\n  id %s", (*(*(*arvore).dec).decfunc).id.name);	
				PercorrePars((*(*(*arvore).dec).decfunc).pars, tblfunc);
				Percorrebl((*(*(*arvore).dec).decfunc).bloco,tblfunc);		
				printf("Imprimindo lista da funcao: ");imprimirlista(tblfunc);			
		//		printf("decfunc analisada: \n");	
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

