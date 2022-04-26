/*
*ALUNO: EMANUEL DÊVID PAULINO FELIX
*MATRÍCULA: 469870
*/
#include <stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){
	Lista* l1 = lst_cria();
	l1 = lst_insere(l1,6);
	l1 = lst_insere(l1,13);
	l1 = lst_insere(l1,25);
	l1 = lst_insere(l1,28);
	l1 = lst_insere(l1,40);
	l1 = lst_remove(l1,25);
	l1 = lst_remove_rec(l1,40);
	printf("======== LISTA 1 ========\n");
	lst_imprime(l1);
	printf("=========================\n");
	printf("==== LISTA 1 INVERTIDA ====\n");
	lst_imprime_invertida_rec(l1);
	printf("===========================\n");
	
	printf("Numero de nohs na lista 1 com info menor que 22: %d\n",menores(l1,22));
	printf("O comprimento da lista 1 eh: %d\n",comprimento(l1));
	printf("Soma dos valores dos nohs da lista 1: %d\n",soma(l1));
	printf("Numero de nohs da lista 1 com valores primos eh: %d\n",primos(l1));
	
	Lista* l2 = lst_cria();
	l2 = lst_insere(l2,28);
	l2 = lst_insere(l2,130);
	printf("======== LISTA 2 ========\n");
	lst_imprime(l2);
	printf("=========================\n");
	
	Lista* l3 = lst_conc(l1,l2);
	printf("==== LISTA 3 (concatenacao das listas 1 e 2) ====\n");
	lst_imprime(l3);
	printf("=================================================\n");
	
	l1 = lst_diferenca(l1,l2);
	printf("======== LISTA 1 (com o(s) elemento(s) em comum com a lsita 2 removido(s)) ========\n");
	lst_imprime(l1);
	printf("===================================================================================\n");
	
	lst_libera(l1);
	lst_libera(l2);
	lst_libera(l3);
	
	system("PAUSE");
	return 0;
}
