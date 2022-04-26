/*ALUNO: EMANUEL DÊVID PAULINO FELIX
MATRÍCULA: 469870
*/
#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

#define N 8

//funções dos slides
typedef struct fila{
	int n;
	int ini;
	int v[N];
}Fila;

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere(Fila *f, int info){
	int fim;
	if(f->n==N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim]= info;
	f->n++;
}

int fila_vazia(Fila *f){
	return f->n==0;
}

int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
 		printf("Fila Vazia!!!\n");
 		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;
	return a;
}

void fila_imprime(Fila *f){
 	int i; int j;
 	for(i = 0; i<f->n;i++){
 		j = (f->ini+i) % N;
 		printf("%d\n",f->v[j]);
 	}
}

//funções do trabalho
void fila_libera(Fila *f){
	free(f);
}

int qtd_maior(Fila* f, int n){
	int i; int j; int quant = 0;
	for(i = 0; i<f->n; i++){
 		j = (f->ini + i) % N;
 		if(f->v[j] > n){
 			quant++;
		 }
 	}
 	return quant;
}

Fila* inverte(Fila* f){
	int i; int k;
	int vet[f->n];
 	for(i = 0; i<f->n;i++){
 		k = (f->ini+i) % N;
 		vet[i] = f->v[k];
 	}
 	int vetI[f->n];
 	int j = 0;
 	for(i = (f->n-1); i>=0;i--){
 		vetI[j] = vet[i];
 		j++;
 	}
 	Fila* fnova = fila_cria();
 	for(i = 0; i<f->n; i++){
 		fila_insere(fnova,vetI[i]);
 	}
 	return fnova;
}

int pares(Fila* f){
	int i; int j; int nPares = 0;
 	for(i = 0; i < f->n; i++){
 		j = (f->ini + i) % N;
 		if(f->v[j]%2 == 0){
 			nPares++;
		 }
 	}
}
