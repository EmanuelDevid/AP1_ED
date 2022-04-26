/*
*ALUNO: EMANUEL DÊVID PAULINO FELIX
*MATRÍCULA: 469870
*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

int main(void){
	int a;
	Pilha* p1 = pilha_cria();
	pilha_push(p1,10);	
	pilha_push(p1,20);
	pilha_push(p1,25);
	pilha_push(p1,30);
	a = pilha_pop(p1);
	
	printf("========== PILHA 1 ==========\n");
	pilha_imprime(p1);
	printf("=============================\n");
	
	printf("Elemento removido da PILHA 1: %d\n",a);
	printf("Elemento no topo da PILHA 1: %d\n",topo(p1));
	printf("Quantidade de elementos impares na PILHA 1: %d\n",impares(p1));
	
	Lista* l1=lst_cria();
	l1 = lst_insere(l1,4);
	l1 = lst_insere(l1,5);
	l1 = lst_insere(l1,6);
	l1 = lst_insere(l1,7);
	
	printf("========== LISTA 1 ==========\n");
	lst_imprime(l1);
	printf("=============================\n");
	
	Lista* l2=lst_cria();
	l2 = lst_insere(l2,5);
	l2 = lst_insere(l2,6);
	l2 = lst_insere(l2,7);
	l2 = lst_insere(l2,8);
	
	printf("========== LISTA 2 ==========\n");
	lst_imprime(l2);
	printf("=============================\n");
	
	Pilha* p2 = empilha_elem_comuns(l1,l2);
	printf("===== Pilha 2 (elementos em comum das listas 1 e 2 empilhados em ordem crescente) =====\n");
	pilha_imprime(p2);
	printf("=======================================================================================\n");
	
	lst_libera(l1);
	lst_libera(l2);
	
	pilha_libera(p1);
	pilha_libera(p2);
	system("PAUSE");
	
	return 0;
}
