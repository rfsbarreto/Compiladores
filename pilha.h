#include <stdio.h>
//#include"bib_Tipos.h"

//Definição dos nós da pilha
typedef struct dado {
	//int a;				
	lista_simb* tbl;
	struct dado* ant;		//Apontador pro elemento empilhado abaixo do atual
} dado; 

//Definição da pilha
typedef struct pilha{
	dado* topo;			//Apontador pro topo da pilha
} pilha;

//Função de inserção
void insert(lista_simb* lista,pilha* p1){
	dado* d1=malloc(sizeof(dado));  //Alocando endereço do novo nó	
	(*d1).tbl=lista;	
	(*d1).ant=(*p1).topo;		//Atribuindo ao novo nó o apontador para o atual topo da pilha
	(*p1).topo=d1;					//Apontando a pilha pro novo nó
	//(*p1).topo = d1;	
	//return;
}

void imprime(pilha* p1){
	dado* aux=(*p1).topo;
	do{
		imprimirlista((*aux).tbl);//{printf("%d ",(*aux).a);
		aux=(*aux).ant;
	}while (aux!=NULL);
	printf("\n");
}

int tamanhopilha(pilha* p1){
	dado* aux=(*p1).topo;
	int cont=0;
	while (aux!=NULL){
//		imprimirlista((*aux).tbl);//{printf("%d ",(*aux).a);
		cont++;
		aux=(*aux).ant;
	};
	return cont;
	//printf("\n");
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
		//printf("Pilha vazia!!\n");	
	return;
}

void pop1(pilha* p1){
	if (!vazia(p1)){	
		//Comandos de correção da referência,quando a pilha não está vazia	
		dado* d;
		d=(*p1).topo;
		(*p1).topo=(*(*p1).topo).ant;  //Desempilhando o elemento do topo
		free(d);
	}else
		//printf("Pilha vazia!!\n");	
	return;
}

//Função que checa se a pilha está vazia
int vazia (pilha* p){
	return ((*p).topo==NULL);
}

/*void main(){
	int valor=0;
	char opc;
	pilha* p = malloc(sizeof(pilha)); //Alocação da pilha
	(*p).topo=NULL;
	do	{ 	//Laço para leitura das opções
		int nlidos = scanf("%c %d", &opc, &valor);
		switch(opc){
			case ('i'):
					insert(valor,p);	
					break;
			case ('r'):
					pop(p);
		}	
	} while (opc!='e'); //determinação da flag pra sair do modo de leitor de entradas
	if (!vazia(p))
		imprime(p);
	else
		printf("Vazia\n");
}*/
