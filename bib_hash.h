//funções hash
#define SIZE 5
#define SHIFT 4
#include "bib_inic.h"




static mng_buckets tabela[SIZE];



int hash(char * chave){
		int temp = 0, i = 0;
		while (chave[i] != '\0'){
			temp = ((temp<< SHIFT)+chave[i])%SIZE;
			++i;
		}	
		return temp;
}	
void Insere(char *nome, int linha, int loc){
	int indice = hash(nome);
	mng_buckets bucket = tabela[indice];
	while ((bucket != NULL) && (nome != (*bucket).nome))
		bucket = (*bucket).proximo;
	if(bucket ==NULL){
			bucket = (mng_buckets) malloc (sizeof(struct mng_buckets_rec));
			(*bucket).nome = nome;
			(*bucket).linha = (mng_linha) malloc (sizeof(struct mng_linha_rec));
			(*(*bucket).linha).linha = linha;
			(*bucket).memloc = loc;
			(*(*bucket).linha).proximo = NULL;
			(*bucket).proximo = tabela[indice];
			tabela[indice] =bucket;
	}else{
		mng_linha l = (*bucket).linha;
		while((*l).proximo != NULL){
			l = (*l).proximo;
		}
		(*l).proximo = (mng_linha) malloc (sizeof(struct mng_linha_rec));
		(*(*l).proximo).linha = linha;
		(*(*l).proximo).proximo = NULL;
	}
}

void Remove(){
		
}

void Verifica(){
	
}
