#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//funções dos slides
typedef struct lista {
	int info;
	Lista *prox;
}Lista;

Lista* lst_cria(){
	return NULL;
}

int lst_vazia(Lista *l){
	return (l == NULL);
}

Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}

Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	while(lAux != NULL){
		if(lAux->info == info)
			return lAux;
 		lAux = lAux->prox;
	}
	return NULL;
}

void lst_imprime(Lista *l){
	Lista* lAux = l;
	while(lAux != NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
	}
}

Lista* lst_remove(Lista *l, int info){
	if(l != NULL){
		Lista* lAux = l->prox;
		if(l->info == info){
	 		free(l);
	 		return lAux;
		}
		else{
			Lista* lAnt = l;
	 		while(lAux != NULL ){
		 		if(lAux->info == info){
					 lAnt->prox = lAux->prox;
					 free(lAux);
					 break;
				 }else{
					 lAnt = lAux;
					 lAux = lAux->prox;
				 	}
	 			}
		}
	}
	return l;
}

void lst_libera(Lista *l){
	Lista* lProx;
	while(l != NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

Lista* lst_remove_rec(Lista *l, int info){
	if(l != NULL){
		if(l->info==info){
	 		return l->prox;
		}
		else{
			l->prox = lst_remove(l->prox,info); 
		}
	}
	return l;
}

void lst_imprime_invertida_rec(Lista *l){
	if(l != NULL){
		lst_imprime_invertida_rec(l->prox);
		printf("Info = %d\n",l->info);
	}
}

//funções do trabalho
int comprimento(Lista* l){
	int n = 0;
	Lista *lAux = l;
	while(lAux != NULL){
		n++;
		lAux = lAux->prox;
	}
	return n;
}

int menores(Lista* l, int n){
	if(l != NULL){
		if(l->info < n){
			return menores(l->prox,n) + 1;
		}else
			return menores(l->prox,n);
	}
}

int soma(Lista* l){
	int soma = 0;
	Lista *lAux = l;
	while(lAux != NULL){
		soma = soma + lAux->info;
		lAux = lAux->prox;
	}
	return soma;
}

int primos(Lista* l){
	if(l != NULL){
		int i;
		int n = l->info;
  		int d = 0;
		for (i = 1; i <= n; i++) {
    		if (n % i == 0) { 
    			d++;
			}
		}
		if (d == 2)
    		return primos(l->prox) + 1;
  		else
    		return primos(l->prox);
	}
}

Lista* lst_inverte(Lista *l){
	if(lst_vazia(l)){
		return l;
	}
	else{
		Lista *lAux = l;
		Lista *lnova = lst_cria();
		int n;
		while(lAux != NULL){
			n = lAux->info;
			lnova = lst_insere(lnova, n);
			lAux = lAux->prox;
		}
		return lnova;
	}
}

Lista* lst_conc(Lista* l1, Lista* l2){
	Lista *lAux1 = l1, *lAux2 = l2;
	Lista *lnova = lst_cria();
	int n;
	if(lst_vazia(l1) || lst_vazia(l2)){
		return l1;
	}
	else{
		while(lAux1 != NULL){
			n = lAux1->info;
			lnova = lst_insere(lnova, n);
			lAux1 = lAux1->prox;
		}
		while(lAux2 != NULL){
			n = lAux2->info;
			lnova = lst_insere(lnova, n);
			lAux2 = lAux2->prox;
		}
		lnova = lst_inverte(lnova);
		return lnova;
	}
}

Lista* lst_diferenca(Lista* l1, Lista* l2){
	Lista* lAux = l2;
	while(lAux != NULL){
		l1 = lst_remove(l1,lAux->info);
		lAux = lAux->prox;
	}
	return l1;
}
