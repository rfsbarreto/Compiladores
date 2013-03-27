#include "bib_Tipos.h"

void imprimirlista(lista_simb* s){
	//	printf("implista ");
		lista_simb* aux=s;
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;
			//variável
			if ((*aux).tipono == 0){
			//	printf("\nvar: %s  ",(*aux).simb.id.name);
//				printf("\ndimensoes: %s  ",(*aux).simb.tipo.qtdACOL);
				//printf("\ntipo2:   ");
//				imprimetipbase((*(*aux).simb.tipo).tipbase);

			}else{
				//printf("\nfunc: %s  ",(*aux).funcao.id.name);
//				printf("\ndimensoes: %s  ",(*aux).funcao.tipo.qtdACOL);
				//printf("\ntipo2:   ");imprimetipbase((*(*aux).funcao.tipo).tipbase);
				if((*aux).funcao.lista != NULL){
					imprimirlista((*aux).funcao.lista);
				}
			}
			
 	       }
}
int tamanho(lista_simb* s){
		//printf("implista ");
		lista_simb* aux=s;
		int cont=-1;
		while ((*aux).prox!=NULL){
			aux=(*aux).prox;
			  cont++;		
 	       }
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
					imprimirlista((*aux).funcao.lista);
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
			if (cont==0 && (tamanho(s)>0 || t==MNG_VAR)){
					printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
	}
	return tip;
}

//void verificasimbolo(lista_simb* s,mng_id id){
void verificasimbolo(lista_simb* s,mng_id id,tipo_no t){

	if(s!=NULL){
		int	cont=0;
		int linha=id.linha;
			lista_simb* aux=s;
			//printf(" VERIFICANDO simbolo %s ",id.name);
			while ((*aux).prox!=NULL){
				aux=(*aux).prox;				
				if (isequal(id.name,(*aux).simb.id.name)){
					//printf("linha : %d linha : %d \n",linha,(*aux).simb.id.linha);
							
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
			if (cont==0 && (tamanho(s)>0 || t==MNG_VAR)){
					//printf("Vriável não declarada na linha : %d \n",linha);
					exit(0);					
			}
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
			if (cont==0 && (tamanho(s)>0 || t==MNG_VAR)){
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
