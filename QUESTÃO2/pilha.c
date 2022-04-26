#include "pilha.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

//funções dos slides
typedef struct lista {
	int info;
	Lista *prox;
}Lista;

typedef struct pilha{
	Lista *prim;
}Pilha; 

Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

void pilha_push(Pilha *p, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

int pilha_vazia(Pilha *p){
	return p->prim == NULL;
}

int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux != NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* lAux;
	while(l != NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(p);
}

//funções do tabalho
int topo(Pilha* p){
	Lista *lAux = p->prim;
	return lAux->info;
	
}

int impares(Pilha* p){
	Lista *lAux = p->prim;
	int nImpares = 0;
	while(lAux != NULL){
		if((lAux->info) %2 != 0){
			nImpares++;
		}
		lAux = lAux->prox;
	}
	return nImpares;
}

Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){
	Lista* lAux1 = l1;
	Lista* lAux2 = lst_cria();
	while(lAux1 != NULL){
		Lista* lAux3 = l2;
		while(lAux3 != NULL){
			if(lAux1->info == lAux3->info){
				lAux2 = lst_insere(lAux2,lAux1->info);
			}
			lAux3 = lAux3->prox;
		}
		lAux1 = lAux1->prox;
	}
	lAux2 = lst_ordena_crescente(lAux2);
	Pilha *pilha = pilha_cria();
	pilha->prim = lAux2;
	return pilha;
}
