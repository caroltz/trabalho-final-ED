#ifndef pilha_h
#define pilha_h

/*
PILHA -> representa o bolo, possui um índice que aponta para o topo
e um ponteiro que aponta para os elementos em um vetor de tamanho 3,
pois contém na posição 0 a base do bolo, na posição 1 a cobertura e 
na posição 2 o enfeite que vai no topo.
*/

#include <stdlib.h>

typedef struct {
	int topo;
	char* bolo;
} pilha;

pilha* inicializaPilha(int tamanho); // dinâmica e sequencial

void destroiPilha(pilha* p);

int inserePilha(pilha* p, char elemento);

int removePilha(pilha* p, char* elemento); //salva no elemento o item removido

#endif