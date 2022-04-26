#include "fila1.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"

//funções dos slides
typedef struct lista{
	int info;
	Lista *prox;
}Lista;

typedef struct fila{
	Lista *ini;
	Lista *fim;
}Fila; 

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
	printf("Memoria insuficiente!!!\n");
	exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
	printf("Memoria insuficiente!!!\n");
	exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
	f->fim = l;
}

int fila_vazia(Fila *f){
	return f->ini==NULL;
}
int fila_remove(Fila *f){
	Lista *l; int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
 	free(l);
	if(fila_vazia(f))
		f->fim = NULL;
 	return a;
}

void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
 	while(lAux!=NULL){
 		printf("%d\n",lAux->info);
 		lAux = lAux->prox;
 	}
}

void fila_libera(Fila *f){
 	Lista* l = f->ini;
 	Lista* lAux;
 	while(l!=NULL){
 		lAux = l->prox;
 		free(l);
 		l = lAux;
 	}
 	free(f);
}

//funções do trabalho
int qtd_maior(Fila* f, int n){
	int quant = 0;
	if(fila_vazia(f)){
		return 0;
	}else{
		Lista* lAux = f->ini;
		while(lAux != NULL){
			if(lAux->info > n){
				quant++;
			}
			lAux = lAux->prox;
		}
	}
	return quant;
}

Fila* inverte(Fila* f){
	Lista *lAux = f->ini;
	Lista *lnova = lst_cria();
	while(lAux != NULL){
		lnova = lst_insere(lnova,lAux->info);
		lAux = lAux->prox;
	}
	lAux = lnova;
	while(lAux->prox != NULL){
		lAux = lAux->prox;
		
	}
	Fila* fnova = fila_cria();
	fnova->ini = lnova;
	fnova->fim = lAux;
	return fnova;
}

int pares(Fila* f){
	Lista *lAux = f->ini;
	int nPares = 0;
 	while(lAux != NULL){
 		if((lAux->info)%2 == 0)
 			nPares++;
 		lAux = lAux->prox;
 	}
 	return nPares;
}
