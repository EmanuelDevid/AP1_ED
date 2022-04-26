#include <stdio.h>
#include<stdlib.h>
#include "fila2.h"

int main(void){
	int a, qtd;
	Fila* f1 = fila_cria();
	fila_insere(f1,10);
	fila_insere(f1,20);
	fila_insere(f1,30);
	fila_insere(f1,40);
	fila_insere(f1,50);
	
	printf("=============== FILA 1 ===============\n");
	fila_imprime(f1);
	printf("======================================\n");
	
	a = fila_remove(f1);
	printf("Valor removido da FILA 1: %d\n",a);
	
	printf("=============== FILA 1 ===============\n");
	fila_imprime(f1);
	printf("======================================\n");
	
	Fila* f2 = inverte(f1);
	printf("========== FILA 2 (LISTA 1 invertida) ==========\n");
	fila_imprime(f2);
	printf("================================================\n");
	
	qtd = qtd_maior(f1,20);
	printf("Numero de elementos maiores que 20 na FILA 1: %d\n",qtd);
	printf("Quantidade de elementos pares na FILA 1: %d\n",pares(f1));
	
	fila_libera(f1);
	fila_libera(f2);
	
	system("PAUSE");
	
	return 0;
}
