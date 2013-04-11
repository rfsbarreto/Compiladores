void Percorredecvar(mng_decvar* decvar,lista_simb* tbl);
void PercorreCmds(mng_decfunc* f, mng_cmds*cmds,lista_simb* tbl);
void PercorreCmd(mng_decfunc* f, mng_cmd* cmd,lista_simb* tbl);
void PercorreDecvars(mng_decfunc* f, mng_decvars * dec,lista_simb* tbl);
void Percorrebl1(mng_decfunc* f, mng_bloco* bl,lista_simb* tbl);
void Percorrebl(mng_decfunc* f, mng_bloco* bl,lista_simb* tbl);
void PercorrePar(mng_par *par,lista_simb* tbl);
void PercorrePars(mng_pars *pars,lista_simb* tbl);
void PercorreListexp(mng_decfunc * f,mng_listexp *listexp,lista_simb* tbl,mng_tip* tip);
void PercorreExp(mng_decfunc * f,mng_exp *exp,lista_simb* tbl);
void PercorreVar(mng_decfunc * f,mng_var *var,lista_simb* tbl);
void PercorreOP(mng_decfunc * f,mng_op *op,lista_simb* tbl);
void imprimetipoPascal(mng_tip*  tip);
pilha* p1;



void imprimetipoPascal(mng_tip*  tip){
	if (tip != NULL)
	if ((*tip).qtdACOL == 0){
		if(imprimetipbase((*tip).tipbase) == "TIPO_INT") printf(":integer ");
		if(imprimetipbase((*tip).tipbase) == "TIPO_VAZIO") printf(" ");
		if(imprimetipbase((*tip).tipbase) == "TIPO_FLOAT") printf(":real ");
		if(imprimetipbase((*tip).tipbase) == "TIPO_STRING") printf(":string ");
		if(imprimetipbase((*tip).tipbase) == "TIPO_CHAR") printf(":char ");
	}else{
		int qtd = (*tip).qtdACOL;
		if(imprimetipbase((*tip).tipbase) == "TIPO_INT"){ 
			printf(":array [");
			while(qtd > 0){
				printf("1..100000000 "); qtd = qtd -1 ;
				if (qtd > 0){
					printf(",");
				}
			}
			printf("] of integer ");
		}
		if(imprimetipbase((*tip).tipbase) == "TIPO_VAZIO")		
			while(qtd > 0){ 
				printf(" ");	 
				qtd = qtd -1 ;
			}
		if(imprimetipbase((*tip).tipbase) == "TIPO_FLOAT"){
			printf(":array ["); 		
			while(qtd > 0){
				printf("1..100000000 ");
				qtd = qtd -1 ;
				if (qtd > 0){
					printf(",");
				}
				printf("] of real ");
			} 
			
		}
		if(imprimetipbase((*tip).tipbase) == "TIPO_STRING"){ 		
			printf(":array ["); 		
			while(qtd > 0){
				printf("1..100000000 ");
				qtd = qtd -1 ;
				if (qtd > 0){
					printf(",");
				}
				printf("] of string ");
			} 		
		}
		if(imprimetipbase((*tip).tipbase) == "TIPO_CHAR"){ 		
			printf(":array ["); 		
			while(qtd > 0){
				printf("1..100000000 ");
				qtd = qtd -1 ;
				if (qtd > 0){
					printf(",");
				}
				printf("] of char ");
			} 
		}				
		
	}
}

void imprimeOPPascal(mng_operadores op){
	if(op == 1){
		printf("+");
	}
	if(op == 2){
		printf("-");
	}
	if(op == 4){
		printf("/");
	}
	if(op == 3){
		printf("*");
	}
	if(op == 5){
		printf("==");
	}
	if(op == 6){
		printf("<=");
	}
	if(op == 7){
		printf(">=");
	}
	if(op == 8){
		printf("<=");
	}
	if(op == 9){
		printf(">=");
	}
	if(op == 11){
		printf("and");
	}
	if(op == 10){
		printf("or");
	}

}

void PercorrePar(mng_par *par,lista_simb* tbl){
	if(par!=NULL){
		//printf("\ntip par: %d", (*par).tip);
	///	printf("\nnome id par: %s", (*par).id.name);
		//printf("var");
		tbl=adicionaVar1( tbl ,(*par).id,(*par).tip ,MNG_PAR );	
		printf("%s",(*par).id.name);
		imprimetipoPascal((*par).tip);
	}
}
	
void PercorrePars(mng_pars* pars,lista_simb* tbl){
	
	mng_pars * p = pars;
		
	while(p != NULL){
		printf("var ");
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
		///printf("Percorrendo Parametros " ); //nome id par: %s \n", (*(*p).par).id.name) ;
		PercorrePar((*p).par, tbl);
		//PercorrePars((*p).pars,tbl);
		if ((*p).pars != NULL){
			p = (*p).pars;
			printf("; ");
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
		printf("%s", (*declistnom).id.name);
		declistnom = (*declistnom).list;
		if(declistnom != NULL) printf(" , ");			

	}
	
	imprimetipoPascal((*decvar).tip); printf("; ");
			
		
	
	//imprimirlista(tbl);
	//return tbl;
}

void Percorrebl1(mng_decfunc* f, mng_bloco* bl,lista_simb* tbl){
	//printf("abre bloco\n");
	mng_bloco * aux= bl;
	if (aux!=NULL){
				//printf("Percorrendo bloco\n"); //nome id par: %s \n", (*(*p).par).id.name) ;
		if ((*aux).decvars!=NULL){
			printf(" var \n");
			PercorreDecvars(f, (*aux).decvars,tbl);
			printf("\n");
		}
		if ((*aux).cmds!=NULL)
			printf(" begin\n");
			PercorreCmds(f, (*aux).cmds,tbl);
			printf(" end;{bloco}\n");
/*<<<<<<< HEAD
	}else{printf("Enasdasdasdad \n");}
======= */
	}//else{printf("\n");}
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	//printf("Encerra bloco \n");
}

void Percorrebl(mng_decfunc* f, mng_bloco* bl,lista_simb* tbl){
	//printf("abre bloco\n");
	mng_bloco * aux= bl;
	if (aux!=NULL){
				//printf("Percorrendo bloco\n"); //nome id par: %s \n", (*(*p).par).id.name) ;
		if ((*aux).decvars!=NULL){
			printf(" var \n");
			PercorreDecvars(f, (*aux).decvars,tbl);
			printf("\n");
		}
		if ((*aux).cmds!=NULL)
//			printf(" begin\n");
			PercorreCmds(f, (*aux).cmds,tbl);
//			printf(" end;{bloco}\n");
/*<<<<<<< HEAD
	}else{printf("Enasdasdasdad \n");}
======= */
	}//else{printf("\n");}
//>>>>>>> d62241ab7d645bf42c6822837112564b7effa506
	//printf("Encerra bloco \n");
}

void PercorreDecvars(mng_decfunc* f,mng_decvars * dec,lista_simb* tbl){
	mng_decvars * decvars = dec;
	while(decvars !=NULL){
		//printf("Percorrendo Decvars\n");
		Percorredecvar((*decvars).decvar, tbl);
		if((*decvars).decvars != NULL){
			decvars = (*decvars).decvars;
		}else break;
	
	}
}

void PercorreCmds(mng_decfunc* f, mng_cmds*cmds,lista_simb* tbl){
		//printf("Percorrendo Cmds\n");
	mng_cmds * atual = cmds;
	while(atual!=NULL){
		//printf("\ncmds");
		PercorreCmd(f, (*atual).cmd, tbl);
		if((*atual).cmds != NULL){
			atual = (*atual).cmds;	}else break;
	}

}

void PercorreListexp(mng_decfunc * f,mng_listexp *listexp,lista_simb* tbl,mng_tip* tip){
	if(listexp != NULL){
		printf("lista exp");
		PercorreExp(f, (*listexp).exp,tbl);
		if ((*listexp).listexp != NULL){
			printf(",");
		}
		PercorreListexp(f, (*listexp).listexp,tbl,tip);
	}
}
void PercorreExp(mng_decfunc * f,mng_exp *exp,lista_simb* tbl){
	printf("\n tipo da exp %d", (*exp).tipoexp);
	//printf("Percorrendo EXP tipo %s ",imprimetipono((*exp).tipoexp));

	if((*exp).tipoexp == MNG_TIPBASE){
	    /*printf(" EXP TIPBASE %d \n",(*exp).tipo);
		if((*exp).tipo != NULL){
                printf("OIIIIIIIIIIIII \n");	
			    	if (imprimetipbase((*(*exp).tipo).tipbase) == "TIPO_INT"){
			    	    printf("%d", (*exp).numint);
			    }
		}
	*/
	}
	if((*exp).tipoexp == MNG_VAR){
		    printf("EXP VAR\n");
		tipo_no t = MNG_VAR;
		(*exp).tipo=verificasimbolo(tbl,(*(*exp).var).id,t);
		VerificavarACOL(tbl,(*(*exp).var).id,t, (*(*exp).var).qtdACOL);
		printf(" %s ",(*(*exp).var).id.name);
		PercorreVar(f,(*exp).var,tbl);	
		printf("FechaVar");
	}
	if((*exp).tipoexp == MNG_EXP){
		    printf("EXP EXP\n");
	//	printf("\nqtd de ACOL:%d ",(*(*exp).tipexp.tip).qtdACOL);
		PercorreExp(f,(*exp).tipexp.exp,tbl);
		struct mng_exp* exp;//DEC(exp);
		
	}
	if((*exp).tipoexp == MNG_CHMET){
		    printf("EXP CHMET\n");
		//printf("metodo: %s \n", (*(*exp).chmet).id.name);
		tipo_no t=MNG_CHMET;
		verificasimbolo(tbl,(*(*exp).chmet).id,t);
		
		pilha * p=p1;
		//printf(" tamanho pilha pro while: %d  ",tamanhopilha(p));
		/*while ((*p).topo!=NULL){
//			verificasimbolo(tbl,(*(*aux).chmet).id,(*(*p).topo).tbl,t);
			printf("Verificando %u!\n",(*(*p).topo).tbl);
			verificachmet((*(*p).topo).tbl,(*exp).chmet,t);
			(*p).topo=(*(*p).topo).ant;

		} */
		
		verificachmet((*(*p).topo).tbl,(*exp).chmet,t);
		printf("{chamada na expressao} \n %s", (*(*exp).chmet).id.name);
		printf("(");
		PercorreListexp(f,(*(*exp).chmet).listexp,tbl,NULL);
		printf(")");

	}
	if((*exp).tipoexp == MNG_TIPEXP){
		    printf("EXP TIPEXP\n");
		PercorreExp(f,(*exp).exp,tbl);
	}
	if((*exp).tipoexp == MNG_OP){
			printf("\nOP: %s ",imprimetipono((*(*(*exp).op).exp1).tipoexp));
        //	printf(" %s \n",imprimetipono((*(*(*exp).op).exp2).tipoexp));
		//	printf("%u %u \n",tbl,f);
		PercorreOP(f,(*exp).op,tbl);
		printf("\n%s \n",imprimetipbase((*(*(*(*exp).op).exp1).tipo).tipbase));
		if ( (*(*(*(*exp).op).exp1).tipo).tipbase==TIPO_FLOAT || (*(*(*(*exp).op).exp2).tipo).tipbase==TIPO_FLOAT)
		    (*(*exp).tipo).tipbase==TIPO_FLOAT;
		else
		    (*(*exp).tipo).tipbase==TIPO_INT;
		printf(" fechou OP %s \n",imprimetipbase((*(*exp).tipo).tipbase));
	}
	if((*exp).tipoexp == MNG_NAO){
		//printf("\nNAO");
		printf("not ");
		PercorreExp(f,(*exp).nao.exp,tbl);		
		if((*(*exp).tipo).tipbase == TIPO_FLOAT
		|| (*(*exp).tipo).tipbase == TIPO_STRING
		|| (*(*exp).tipo).tipbase == TIPO_VAZIO){
			//printf("operação de não com tipo inválido");
		}
	}
	//	printf("FIM EXP \n");
}

void PercorreOP(mng_decfunc * f,mng_op *op,lista_simb* tbl){
		printf("\nOperação na linha %d ", (*op).linha);
	//printf("OP1: tipo-> %s  %s  ",imprimetipono((*(*op).exp1).tipoexp),imprimetipono((*(*op).exp2).tipoexp));//,imprimetipono((*(*(*(*op).exp1).op).exp1).tipoexp));
	//printf("\nOperação na linha %d ", (*op).linha);
	PercorreExp(f,(*op).exp1,tbl);
	//imprimeOPPascal((*op).op);
		//printf(" Tipo da operação: %d \n");
	//printf(" Tipo da operação: %d ",(*op).op);
	PercorreExp(f,(*op).exp2,tbl);
	//printf(" Fechou OP: %d",(*op).op);
}



void PercorreVar(mng_decfunc * f,mng_var *var,lista_simb* tbl){
	printf("Perc Var");
 	while(var != NULL){
		printf(" Percorrendo Var: %d",var);
		//printf("acol %d", (*var).qtdACOL);
		//printf("\nnome da var:%s ",(*var).id.name);
		if ((*var).qtdACOL != 0){
			printf(" [");
			if ((*var).exp != NULL){
				
				PercorreExp(f,(*var).exp,tbl);
				printf(" {expressão} ");

			}
			printf(" ]\n");
		}
		if((*var).var != NULL){
			var = (*var).var;
		}else{ break;}
		
		//printf("\nqtd de ACOL:%d ",(*var).qtdACOL);
	}
	printf("Perc Var1");
}




void PercorreCmd(mng_decfunc* f,mng_cmd* cmd,lista_simb* tbl){
	mng_cmd* aux = cmd;
	if((*aux).tipocmd == MNG_IF){
		printf(" if");
		PercorreExp(f,(*aux).decif.exp,tbl);
		printf(" then begin\n");
		PercorreCmd(f, (*aux).decif.cmd,tbl); 

		if((*aux).decif.ptelse != NULL){
			printf(" end \n else begin");		
			if((*(*aux).decif.ptelse).cmd != NULL){
				PercorreCmd(f, (*(*aux).decif.ptelse).cmd,tbl);
			}
		}else{
			printf(" end;{end do if}\n");
		}

	}
	if((*aux).tipocmd == MNG_WHILE){
		printf(" while ");
		PercorreExp(f,(*aux).decwhile.exp,tbl);
		printf(" do \n begin\n");

		if ((*aux).decwhile.cmd!=NULL){
			PercorreCmd(f, (*aux).decwhile.cmd,tbl);
		}
		printf(" end;{end do while}\n");




	}
	if((*aux).tipocmd == MNG_ATRIB){

		tipo_no t=MNG_VAR;

		verificasimbolo(tbl,(*(*(*aux).atrib).var).id,t);
		printf("%s :=", (*(*(*aux).atrib).var).id.name);
		PercorreExp(f,(*(*aux).atrib).exp,tbl);
		

			if ((*(*(*aux).atrib).exp).tipoexp == MNG_TIPEXP){	

				VerificavarACOL(tbl,(*(*(*aux).atrib).var).id,t, (*(*(*aux).atrib).var).qtdACOL);
				if((*(*(*aux).atrib).var).qtdACOL > (*(*(*(*aux).atrib).exp).tipexp.tip).qtdACOL){
					printf("Erro na linha, variáveis de tipos diferentes : %d \n",(*(*(*aux).atrib).var).id.linha);
				}
				
				//Verificatipo(tbl,(*(*(*aux).atrib).var).id,t,(*(*(*aux).atrib).exp).tipexp.tip);
				PercorreExp(f,(*(*(*aux).atrib).exp).tipexp.exp, tbl);
			}
		printf(";\n");
	}




	if((*aux).tipocmd == MNG_RETURN){
		
		if ((*aux).ret.tipret == RET_EXP){
			
			
			printf("%s := ", (*f).id.name);			
			PercorreExp(f,(*aux).ret.exp,tbl);
			if ((*(*f).tip).tipbase!=(*(*(*aux).ret.exp).tipo).tipbase){
			    printf("Erro na linha %d. Tipo de Retorno diferente", (*aux).linha);
			    exit(0);
			}
			printf(";{return com exp} \n ");
			
		}else{
		//	printf("\nreturn ;");	
		}
	}


	if((*aux).tipocmd == MNG_CHMET){
		//printf("\nchamada ao método id : %s \n", (*(*aux).chmet).id.name);
		tipo_no t=MNG_CHMET;
		mng_tip* tip = verificasimbolo(tbl,(*(*aux).chmet).id,t);
		printf("%s", (*(*aux).chmet).id.name);
		printf("(");
	
		pilha * p=p1;
		//printf("pilha %u",p);
	///	printf(" tamanho pilha pro while: %d  ",tamanhopilha(p));
	/*	while ((*p).topo!=NULL){
//			verificasimbolo(tbl,(*(*aux).chmet).id,(*(*p).topo).tbl,t);
		//	printf("Verificando!");
			verificachmet((*(*p).topo).tbl,(*aux).chmet,t);
			(*p).topo=(*(*p).topo).ant;

		} */ 
		//verificachmet(tbl,(*aux).chmet,t);
		PercorreListexp(f,(*(*aux).chmet).listexp,tbl,tip);
		printf(")");
		
	}
	if((*aux).tipocmd == MNG_BLOCO){
		//printf("\npercorre bloco dentro do cmd\n");
		//tipo_no t=MNG_BLOCO;
		//erificasimbolo(tbl,(*(*aux).chmet).id,t);
		Percorrebl(f, (*aux).bloco,tbl);
	//	printf("\nMNG_BLOCO");

	}

}

void PercorreArvore(mng_prg* arvore,lista_simb* tbl){
//	printf("Percorrendo árvore: \n");	
	if(arvore != NULL){
		
		lista_simb* tabela;		
		if (tbl==NULL){
			tabela=	(lista_simb*) malloc(sizeof(lista_simb));
			//printf("Endereço tabela %u ",tabela);
			p1=(pilha*) malloc(sizeof(pilha));
			(*p1).topo=NULL;
			printf("program monga;\n");
		}else
			tabela=tbl;
		//printf("\ntipo no dec : %d ", (*(*arvore).dec).tipodec);
		if ((*(*arvore).dec).tipodec == MNG_DECVAR){
			//decvar
			printf("var\n");
	//	printf("Percorrendo árvore( decvar): \n");	
			if((*(*arvore).dec).decvar){
				//printf("Endereço da PILHA e do topo dela: %u %u \n",p1,(*p1).topo);
				Percorredecvar((*(*arvore).dec).decvar, tabela);
			}
			}else{
			if((*(*arvore).dec).decfunc != NULL){
	  			printf("function");
				while (tamanhopilha(p1)>1){
//					printf("POP!");
pop(p1);
				}				
				insert(tabela,p1);
//				printf("Percorrendo árvore( decfunc): \n");	
//							printf("Endereço tabela %u %u ",tabela,(*tabela).prox);
//				printf("Endereço da PILHA e do topo dela: %u %u \n",p1,(*p1).topo);
				tipo_no t=MNG_DECFUNC;
				verificasimbolo(tabela,(*(*(*arvore).dec).decfunc).id,t);
				printf(" %s",(*(*(*arvore).dec).decfunc).id.name);
//				verificasimbolo(tbl,(*(*(*arvore).dec).decfunc).id);//,t);
//				printf("vamo ver")				;
				lista_simb* tblfunc= (lista_simb*) malloc(sizeof(lista_simb));
			//	printf("\ntipo decfunc", (*(*(*arvore).dec).decfunc).tip);			
				//printf("\n  id %s", (*(*(*arvore).dec).decfunc).id.name);
				printf("(");	
				PercorrePars((*(*(*arvore).dec).decfunc).pars, tblfunc);
				printf(")");
				imprimetipoPascal((*(*(*arvore).dec).decfunc).tip); printf(";\n");
				
				Percorrebl1((*(*arvore).dec).decfunc, (*(*(*arvore).dec).decfunc).bloco,tblfunc);		
//				printf("Imprimindo lista da funcao: ");imprimirlista(tblfunc);			
		//		printf("decfunc analisada: \n");	
				adicionaFunc(tabela, (*(*arvore).dec).decfunc,tblfunc);

				
				
			

			}
			
			
			
		}

		if((*arvore).prog != NULL){
			//imprimirlista(tabela);
			PercorreArvore((*arvore).prog,tabela);
		}
		else{
			//imprimirlista(tabela);
			printf("begin\n"); 
			printf("end. {end do programa}\n");
				//printf("Imprimindo lista FINAL: ");
				
}
	}else{
		printf("program monga;\n");
		printf("begin\n"); 
		printf("end.\n");

	}

//	printf("arvore vazia");//imprimirlista(tabela);	
}

