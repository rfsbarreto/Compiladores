#include "bib_Tipos.h"
#include "pilha.h"

void imprimirlista(lista_simb* s){
	//	printf("implista ");
		lista_simb* aux=s;
		//printf("\n")
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;
			printf("end: %u ",aux);
			//variável
			if ((*aux).tipono == 0){
				printf("var: %s ",(*aux).simb.id.name);
//				printf("\ndimensoes: %s  ",(*aux).simb.tipo.qtdACOL);
				printf("ntipo2: %s ->  ",imprimetipbase((*(*aux).simb.tipo).tipbase));

			}else{
				printf("func: %s  ",(*aux).funcao.id.name);
//				printf("\ndimensoes: %s  ",(*aux).funcao.tipo.qtdACOL);
				printf("tipo2: %s -> ",imprimetipbase((*(*aux).funcao.tipo).tipbase) );
				if((*aux).funcao.lista != NULL){
					imprimirlista((*aux).funcao.lista);
				}
			}
				
 	       }
		printf("%s \n",(*aux).prox);
}


void imprimirlistaprog(mng_prg* s){
	//	printf("implista ");
		mng_prg* aux=s;
		while (aux!=NULL){
//			aux=(*aux).prox;
			//variável
		//	if ((*aux).tipono == 0){
				printf(" dec.tipo: %u -> ",(*(*aux).dec).tipodec);
				//printf(" dec.qtdPAR: %u -> ",(*(*(*aux).dec).qtdPars);
				aux=(*aux).prog;
//				printf("\ndimensoes: %s  ",(*aux).simb.tipo.qtdACOL);
//				printf("\ntipo2:   ");
			//	imprimetipbase((*(*aux).dec.tipo).tipbase);

		//	}else{
		//		printf("\nfunc: %s  ",(*aux).funcao.id.name);
//				printf("\ndimensoes: %s  ",(*aux).funcao.tipo.qtdACOL);
		//		printf("\ntipo2:   ");imprimetipbase((*(*aux).funcao.tipo).tipbase);
		//		if((*aux).funcao.lista != NULL){
		//			imprimirlista((*aux).funcao.lista);
		//		}
		//	}
			
 	       }
		//printf("%s",aux);
}

void imprimirlistadec(mng_dec* s){
	//	printf("implista ");
		mng_dec* aux=s;
		
//			aux=(*aux).prox;
			//variável
			if ((*aux).tipodec == MNG_DECVAR){
				printf(" dec.vars: %s -> ",imprimirlistanome((*(*aux).decvar).p_listnom));	
				printf(" dec.var.tpbase: %s -> ",imprimetipbase((*(*(*aux).decvar).tip).tipbase));
//				printf(" dec.qtdPAR: %u -> ",(*(*(*aux).dec).qtdPars);
			}else{
				printf(" dec.func: %s -> ",(*(*aux).decfunc).id.name);
				printf(" decfunc.qtdPAR: %d -> ",(*(*aux).decfunc).qtdPars);
				printf(" decfunc.tipo: %s -> ",imprimetipbase((*(*(*aux).decfunc).tip).tipbase));			
			}
	
//			aux=(*aux).prog;

			
 	    
		//printf("%s",aux);
}

void imprimirlistanome(mng_listnom* s){
		mng_listnom* a=s;
		while (a!=NULL){
			printf(" %s ",(*a).id);
			a=(*a).list;
		}

}




int tamanholista(lista_simb* s){
		
		lista_simb* aux=s;
		int cont=0;
		while ((*aux).prox!=NULL){
			///printf("tamanho ");		
			aux=(*aux).prox;
			  cont++;		
 	       }
		return cont;
}

int tamanholistaexp(mng_listexp* s){
		
		mng_listexp* aux=s;
		int cont=0;
		while ((aux)!=NULL){
			///printf("tamanho ");		
			aux=(*aux).listexp;
			  cont++;		
 	       }
		return cont;
}



void procuraNome(lista_simb* s, char*nome){
	//	printf("implista ");
		lista_simb* aux=s;
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;
			//variável
			if ((*aux).tipono == 0){
		//		printf("\nvar: %s  ",(*aux).simb.id.name);
			//printf("\ntipo: ");imprimetipono((*(*aux).simb.tipo).tipbase);

			}else{
				//printf("\nfunc: %s  ",(*aux).funcao.id.name);
				//printf("\ntipo: ");imprimetipono((*(*aux).funcao.tipo).tipbase);
				if((*aux).funcao.lista != NULL){
					//imprimirlista((*aux).funcao.lista);
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
			if (isequal(id.name,(*aux).simb.id.name)){
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

mng_tip* verificavar(lista_simb* s,mng_id id,tipo_no t){
	mng_tip * tip;
	if(s!=NULL){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;
			//printf(" VERIFICANDO simbolo %s ",id.name);
			while ((*aux).prox!=NULL){
				aux=(*aux).prox;				
				if (isequal(id.name,(*aux).simb.id.name)){
				////////	printf("linha : %d linha : %d \n",linha,(*aux).simb.id.linha);
			
					//tip =	(*aux).simb.tipo;	
		
							
					if((*aux).simb.id.linha>=linha)
						linha=(*aux).simb.id.linha;
//					else
//						linha=(*aux).simb.linha;
					cont++;				
				}			
			}
		//	printf("\n\n\tcontador: %d \n\n",cont);
			if ( (cont>0) && (t== MNG_DECVAR || t==MNG_DECFUNC)){
					printf("Erro na linha : %d \n",linha);
					exit(0);					
			}	
//			if (cont>0 && t== MNG_ID){
//					printf("Erro na linha : %d \n",linha);
//					exit(0);					
//			}	
			//printf("tamanho S : %d \n",tamanho(s));
			if (cont==0 && (tamanholista(s)>0 || t==MNG_VAR)){
					printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
	}
	return tip;
}

//void verificasimbolo(lista_simb* s,mng_id id){
mng_tip* verificasimbolo(lista_simb* s,mng_id id,tipo_no t){

	//imprimirlista(s);
	if(s!=NULL){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;
			///printf("\n VERIFICANDO simbolo %s %u %u",id.name,(*aux).prox,aux) ;
			while ((*aux).prox!=NULL){
			//	printf("\n VERIFICANDO simbolo %s na tabela %u ",id.name,aux);
				aux=(*aux).prox;			
				//printf("\n VERIFICANDO simbolo %s na tabela %u ",id.name,aux);	
				//printf("\nimprimindo lista: ");imprimirlista(aux);
				//printf("\nteste %s",(*aux).funcao.id.name);
				//printf("\nteste %s",(*aux).simb.id.name);
			//if 
				
			if (isequal(id.name,((*aux).tipono==0)?((*aux).simb.id.name):((*aux).funcao.id.name ) ) ) {
					//printf("linha : %d linha : %d \n",linha,(*aux).simb.id.linha);
							
					if((*aux).simb.id.linha>=linha)
						linha=(*aux).simb.id.linha;

//					else
//						linha=(*aux).simb.linha;
					cont++;				
										break;
				}			
		 }  	
			//printf("\tcontador: %d \n",cont);
		//	imprimirlista(s);
			if ( (cont>0) && (t== MNG_DECVAR || t==MNG_DECFUNC)){
					printf("Erro na linha : %d \n",linha);
					exit(0);					
			}	
//			if (cont>0 && t== MNG_ID){
//					printf("Erro na linha : %d \n",linha);
//					exit(0);					
//			}	
		//	printf("tamanho S : %d \n",tamanholista(s));
			if ( (cont>0) && (t== MNG_CHMET)){
				//	printf("QTDPAR: %d  ",(*aux).funcao.qtdPars);
				//	printf("Erro na linha : %d \n",linha);
					
					//exit(0);					
			}	
			//printf("tamanho t  S : %s %d \n",imprimetipono(t),tamanholista(s));
			//printf("aaaaa\n");
			
			if (cont==0 && ( /*tamanholista(s)>0 ||*/ t==MNG_VAR)){
					printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
		return ( ( (*aux).tipono==0)?((*aux).simb.tipo):((*aux).funcao.tipo ) );
	//printf("\n TERMINOU VERIFICAçao simbolo  ");
	//printf("tamaassadnho S : %d \n",tamanholista(s));
	}
	
}

mng_tip* RetornaTipoVar(lista_simb* s,mng_id id){
	int tamanho= sizeof(mng_tip);
	mng_tip * tip = (mng_tip*) malloc(tamanho);
	
		if(s!=NULL){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;
			
			while ((*aux).prox!=NULL){
			
				aux=(*aux).prox;			
		
				if (isequal(id.name,((*aux).tipono==0)?((*aux).simb.id.name):((*aux).funcao.id.name ) ) ) {
					
					tip = (*aux).simb.tipo;	
					printf("quantidade acol %d", (*(*aux).simb.tipo).qtdACOL);
					if((*aux).simb.id.linha>=linha)
						linha=(*aux).simb.id.linha;

					cont++;				
										break;
				}			
		 }  	
			


	}
	return tip;
}





void VerificavarACOL(lista_simb* s,mng_id id,tipo_no t, int qtdACOL){
	//imprimirlista(s);
	if(s!=NULL ){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;

			while ((*aux).prox!=NULL){
				aux=(*aux).prox;			
		
				
			if (isequal(id.name,((*aux).tipono==0)?((*aux).simb.id.name):((*aux).funcao.id.name ) ) ) {
		
					if ((*(*aux).simb.tipo).qtdACOL < qtdACOL){
						printf("Erro na linha, variáveis de tipos diferentes : %d \n",linha);
						exit(0);
					}
							
					if((*aux).simb.id.linha>=linha)
						linha=(*aux).simb.id.linha;

					cont++;				
										break;
				}			
		 }  	

			if ( (cont>0) && (t== MNG_DECVAR || t==MNG_DECFUNC)){
					printf("Erro na linha : %d \n",linha);
					exit(0);					
			}	
//			if (cont>0 && t== MNG_ID){
//					printf("Erro na linha : %d \n",linha);
//					exit(0);					
//			}	
		//	printf("tamanho S : %d \n",tamanholista(s));
			if ( (cont>0) && (t== MNG_CHMET)){
				//	printf("QTDPAR: %d  ",(*aux).funcao.qtdPars);
				//	printf("Erro na linha : %d \n",linha);
					
					//exit(0);					
			}
			
			//printf("tamanho t  S : %s %d \n",imprimetipono(t),tamanholista(s));
			//printf("aaaaa\n");
			if (cont==0 && ( /*tamanholista(s)>0 ||*/ t==MNG_VAR)){
					printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
	
	//printf("\n TERMINOU VERIFICAçao simbolo  ");
	//printf("tamaassadnho S : %d \n",tamanholista(s));
	}
}


void Verificatipo(lista_simb* s,mng_id id,tipo_no t, mng_tip*tip){

	//imprimirlista(s);
	if(s!=NULL){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;
		//	printf("\n VERIFICANDO simbolo %s %u %u",id.name,(*aux).prox,aux) ;
			while ((*aux).prox!=NULL){
			//	printf("\n VERIFICANDO simbolo %s na tabela %u ",id.name,aux);
				aux=(*aux).prox;			
			//	printf("\n VERIFICANDO simbolo %s na tabela %u ",id.name,aux);	
				//printf("\nimprimindo lista: ");imprimirlista(aux);
				//printf("\nteste %s",(*aux).funcao.id.name);
				//printf("\nteste %s",(*aux).simb.id.name);
			//if 
				
			if (isequal(id.name,((*aux).tipono==0)?((*aux).simb.id.name):((*aux).funcao.id.name ) ) ) {
					
					if ((*(*aux).simb.tipo).tipbase != (*tip).tipbase){
						printf("Erro na linha, variáveis de tipos diferentes : %d \n",linha);
						exit(0);
					}
							
					if((*aux).simb.id.linha>=linha)
						linha=(*aux).simb.id.linha;

//					else
//						linha=(*aux).simb.linha;
					cont++;				
										break;
				}			
		 }  	
			//printf("\tcontador: %d \n",cont);
		//	imprimirlista(s);
			if ( (cont>0) && (t== MNG_DECVAR || t==MNG_DECFUNC)){
					printf("Erro na linha : %d \n",linha);
					exit(0);					
			}	
//			if (cont>0 && t== MNG_ID){
//					printf("Erro na linha : %d \n",linha);
//					exit(0);					
//			}	
		//	printf("tamanho S : %d \n",tamanholista(s));
			if ( (cont>0) && (t== MNG_CHMET)){
					printf("QTDPAR: %d  ",(*aux).funcao.qtdPars);
				//	printf("Erro na linha : %d \n",linha);
					
					//exit(0);					
			}
			
			printf("tamanho t  S : %s %d \n",imprimetipono(t),tamanholista(s));
			printf("aaaaa\n");
			if (cont==0 && ( /*tamanholista(s)>0 ||*/ t==MNG_VAR)){
					printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
	
	printf("\n TERMINOU VERIFICAçao simbolo  ");
	//printf("tamaassadnho S : %d \n",tamanholista(s));
	}
}


lista_simb* verificachmet(lista_simb* s,mng_chmet* met,tipo_no t){//,pilha * p1){

	int qtdpars=0;
	mng_listexp* l = (*met).listexp;
//	printf("qtdpars: %d \n",qtdpars);
	qtdpars=tamanholistaexp(l);
	//printf("\n\n Verificando a chamada");
//	printf("qtdpars: %d \n",qtdpars);
	if(s!=NULL){
		int	cont=0;
		int linha=(*met).id.linha;
			lista_simb* aux=s;
			//printf("\n VERIFICANDO %s ",(*met).id.name);
			while ((*aux).prox!=NULL){
				aux=(*aux).prox;				
				if ( (*aux).tipono==1 && isequal( (*met).id.name, (*aux).funcao.id.name ) ) {
				//	printf("Encontrei a função da chamada ");
							
					if((*aux).funcao.id.linha>=linha)
						linha=(*aux).funcao.id.linha;
//					else
//						linha=(*aux).simb.linha;
					cont++;		
					break;		
				}			
			}
//			printf("\tcontador: %d \n",cont);
		//	imprimirlista(s);


			if ( (cont>0)){
				//	printf("Vou fazer a verificação");

					if (qtdpars==(*aux).funcao.qtdPars)	{
						int i;
						if ((*(*aux).funcao.lista).prox != NULL && (*met).listexp != NULL){
						lista_simb* b=(*(*aux).funcao.lista).prox;
						mng_listexp* e= (*met).listexp;	
						//printf("%s",imprimetipbase((*(*(*e).exp).tipo).tipbase));			
						while( e != NULL && b != NULL) {	
							if( (*(*e).exp).tipoexp == MNG_VAR){
								int tamanho= sizeof(mng_tip);
								mng_tip * tipaux = (mng_tip*) malloc(tamanho);
							

								//printf("\ntipo da variável\n");
								if((*(*e).exp).var != NULL){
									tipaux = RetornaTipoVar(s,(*(*(*e).exp).var).id);							
									if((*tipaux).tipbase != (*(*b).simb.tipo).tipbase){
										printf("Erro na linha %d. Função chamada possui parâmetros com tipos diferentes \n",linha);
										exit(0);
									}
									//printf("quantidade de acol de var %d",(*tipaux).qtdACOL) ;	
									//printf("quantidade de acol do par %d", (*(*b).simb.tipo).qtdACOL) ;	
									//vou procurar onde a variável foi declarada para saber se a quantidade de ACOL é a igual a esperada pela função chamada
																		
									if((*tipaux).qtdACOL != (*(*b).simb.tipo).qtdACOL){
										printf("Erro na linha %d. Função chamada possui parâmetros com tipos diferentes \n",linha);
										exit(0);
									}
//									verificavarACOL(s, (*(*(*e).exp).var).id, MNG_VAR, (*(*(*e).exp).var).qtdACOL);
								}
								
								//if((*(*(*e).exp).var).qtdACOL != 
															
							}
		
							e = (*e).listexp;
							b = (*b).prox;	
						}							
}	
					} else	{			
						if (qtdpars>(*aux).funcao.qtdPars)
							printf("Erro na linha %d. Função chamada possui menos parâmetros  \n",linha);
						else	
						//if (qtdpars<(*aux).funcao.qtdPars)
							printf("Erro na linha %d. Função chamada possui mais parâmetros  \n",linha);
						exit(0);					
						}
			}	
/*			if (cont==0 && (tamanholista(s)>0 || t==MNG_VAR)){
					printf("Variável não declarada na linha : %d \n",linha);
					exit(0);					
			}*/ 
	}
	}



















lista_simb* verificalistanomes(lista_simb* s,mng_chmet* met,tipo_no t){//,pilha * p1){

	int qtdpars=0;
	mng_listexp* l = (*met).listexp;
//	printf("qtdpars: %d \n",qtdpars);
	qtdpars=tamanholistaexp(l);

//	printf("qtdpars: %d \n",qtdpars);
	if(s!=NULL){
		int	cont=0;
		int linha=(*met).id.linha;
			lista_simb* aux=s;
		//	printf("\n VERIFICANDO %s ",(*met).id.name);
			while ((*aux).prox!=NULL){
				aux=(*aux).prox;				
				if ( (*aux).tipono==1 && isequal( (*met).id.name, (*aux).funcao.id.name ) ) {
					//printf("linha : %d linha : %d \n",linha,(*aux).simb.id.linha);
							
					if((*aux).funcao.id.linha>=linha)
						linha=(*aux).funcao.id.linha;
//					else
//						linha=(*aux).simb.linha;
					cont++;		
					break;		
				}			
			}
			//printf("\tcontador: %d \n",cont);
		//	imprimirlista(s);


			if ( (cont>0) && (t== MNG_CHMET)){
					//printf("qtdpars: %d %d \n",qtdpars,(*aux).funcao.qtdPars);
				//	imprimirlista((*aux).funcao.lista);
					if (qtdpars==(*aux).funcao.qtdPars)	{
						int i;
						lista_simb* b=(*(*aux).funcao.lista).prox;
						mng_listexp* e= (*l).listexp	;	
				//		printf("%s",imprimetipbase((*(*(*e).exp).tipo).tipbase));				
						for (i=1;i<=qtdpars;i++){
							//b=(*(*aux).funcao.lista);
							//mng_listexp* e= (*(*l).listexp)	;
						/*	if ( (*(*(*e).exp).tipo).tipbase != (*(*b).simb.tipo).tipbase 
								|| (*(*(*e).exp).tipo).qtdACOL != (*(*b).simb.tipo).qtdACOL  )
								printf("Erro na linha %d. Tipos dos parametroes são diferentes  \n",linha);
							else{
												
							}														
						*/
						}							

					} else	{			
						if (qtdpars>(*aux).funcao.qtdPars)
							printf("Erro na linha %d. Função chamada possui menos parâmetros  \n",linha);
						else	
						//if (qtdpars<(*aux).funcao.qtdPars)
							printf("Erro na linha %d. Função chamada possui mais parâmetros  \n",linha);
						exit(0);					
						}
			}	
/*			if (cont==0 && (tamanholista(s)>0 || t==MNG_VAR)){
					printf("Variável não declarada na linha : %d \n",linha);
					exit(0);					
			}*/ 
	}
	}















//void verificasimbolo(lista_simb* s,mng_id id){
void verificatipo(lista_simb* s,mng_tip * tip, mng_id id, tipo_no t){

	if(s!=NULL){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;
			//printf(" VERIFICANDO simbolo %s ",id.name);
			while ((*aux).prox!=NULL){
				aux=(*aux).prox;	
				if (((*tip).tipbase==(*(*aux).simb.tipo).tipbase) && isequal(id.name,(*aux).simb.id.name)){
				//	printf("linha : %d linha : %d \n",linha,(*aux).simb.id.linha);			
					if((*aux).simb.id.linha>=linha)
						linha=(*aux).simb.id.linha;
//					else
//						linha=(*aux).simb.linha;
					cont++;				
				}			
			}
		//	printf("\n\n\tcontador: %d \n\n",cont);
			if ( (cont>0) && (t== MNG_DECVAR || t==MNG_DECFUNC)){
					printf("Erro na linha : %d \n",linha);
					exit(0);					
			}	
//			if (cont>0 && t== MNG_ID){
//					printf("Erro na linha : %d \n",linha);
//					exit(0);					
//			}	
			//printf("tamanho S : %d \n",tamanho(s));
			if (cont==0 && (tamanholista(s)>0 || t==MNG_VAR)){
					printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
	}
	
}





void verificasimbolos(lista_simb* s,mng_listnom* listnom){

	if(s!=NULL){
		//int	cont=0;
		tipo_no t=MNG_DECVAR;
		mng_listnom* l=listnom;
		while (l!=NULL){
			lista_simb* aux=s;
			
			verificasimbolo(s,(*l).id,t);
//			verificasimbolo(s,(*l).id);
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
