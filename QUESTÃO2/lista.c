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
	return (l==NULL);
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

void lst_imprime_invertida_rec(Lista *l){
	if(l != NULL){
		lst_imprime_invertida_rec(l->prox);
		printf("Info = %d\n",l->info);
	}
}

//funções do trabalho
Lista* lst_ordena_crescente(Lista *l){
	int v = 1;
	while(v == 1){
	Lista* lAux = l;
	Lista* ant = l;
	Lista* prox = l->prox;
	int soma = 0;
		while(lAux != NULL){
			if(prox == NULL){
				break;
			}
			if(ant->info < prox->info){
				int a = ant->info;
				ant->info = prox->info;
				prox->info = a;
				ant = prox;
				prox = prox->prox;
			}else{
				ant = prox;
				prox = prox->prox;
			}
			lAux = lAux->prox;
		}
		ant = l;
		prox = l->prox;
		lAux = l;
		while(lAux != NULL){
			if(prox == NULL){
				break;
			}
			if(ant->info < prox->info){
				soma++;
			}
			ant = prox;
			prox = prox->prox;
			lAux = lAux->prox;
		}
		if(soma == 0){
			v = 0;
		}
	}
	
	return l;
}
