#include <stdio.h>
#include <stdlib.h>
//#include"bib_Tipos.h"
typedef struct tip{
	int* a;
}tip;


//Definição dos nós da pilha
typedef struct dado {
	 tip* a;				
	//lista_simb* tbl;
	struct dado* ant;		//Apontador pro elemento empilhado abaixo do atual
} dado; 

//Definição da pilha
typedef struct pilha{
	dado* topo;			//Apontador pro topo da pilha
} pilha;

//Função de inserção
void insert(tip* t,pilha* p1){
printf("entrou");
	dado* d1=(dado*) malloc(sizeof(dado));  //Alocando endereço do novo nó	
	(*d1).a=t;	
	(*d1).ant=(*p1).topo;		//Atribuindo ao novo nó o apontador para o atual topo da pilha
	(*p1).topo=d1;					//Apontando a pilha pro novo nó

printf("saiu");
	//(*p1).topo = d1;	
//	return;
}

void imprime(pilha* p1){
	dado* aux=(*p1).topo;
	do{
		//iprimirlista((*aux).tbl);//{printf("%d ",(*aux).a);
		printf("%d ",(*(*(*aux).a).a));
		aux=(*aux).ant;
	}while (aux!=NULL);
	printf("\n");
}

//Função para desempilhar
void pop(pilha* p1){
	if (!vazia(p1)){	
		//Comandos de correção da referência,quando a pilha não está vazia	
		dado* d;
		d=(*p1).topo;
		(*p1).topo=(*(*p1).topo).ant;  //Desempilhando o elemento do topo
		free(d);
	}else
		printf("Pilha vazia!!\n");	
	return;
}

//Função que checa se a pilha está vazia
int vazia (pilha* p){
	return ((*p).topo==NULL);
}

void main(){
//	printf("M");
	tip* valor;
	char opc;
	pilha* p = malloc(sizeof(pilha)); //Alocação da pilha
	(*p).topo=NULL;
//	do	{ 	//Laço para leitura das opções
	//	int nlidos = scanf("%c %d", &opc, &valor);
	//	switch(opc){
	//		case ('i'):
					int* h ;//= (int*) malloc(sizeof(int));  //Alocando endereço do novo nó	
					valor=(tip*) malloc(sizeof(tip));  //Alocando endereço do novo nó	
					(*h)=2;
					(*valor).a=h;
					insert(valor,p);	
					h = (int*) malloc(sizeof(int));  //Alocando endereço do novo nó	
					valor=(tip*) malloc(sizeof(tip));  //Alocando endereço do novo nó	
					(*h)=5;
					(*valor).a=h;
					insert(valor,p);	
					int* j=NULL;
					printf("\n%s \n",j);
				/*	printf("Z");
					valor=(tip*) malloc(sizeof(tip));  //Alocando endereço do novo nó	
					(*(*valor).a)=3;
					insert(valor,p);	
					valor=(tip*) malloc(sizeof(tip));  //Alocando endereço do novo nó	
					(*(*valor).a)=7;
					insert(valor,p);	
			*/
	//				break;
	//		case ('r'):
	//				pop(p);
	//	}	
//	} while (opc!='e'); //determinação da flag pra sair do modo de leitor de entradas
	if (!vazia(p))
		imprime(p);
	else
		printf("Vazia\n");
}
