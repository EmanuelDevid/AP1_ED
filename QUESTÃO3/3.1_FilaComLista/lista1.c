#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"

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
