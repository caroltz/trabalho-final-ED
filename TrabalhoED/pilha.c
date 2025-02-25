#include <stdlib.h>
#include "pilha.h"

#define MAX 3

pilha* inicializaPilha(int tamanho) {
	pilha* p = (pilha*)malloc(sizeof(pilha));
	p->topo = 0;
	p->bolo = (char*)malloc(tamanho * sizeof(char));
	return p;
}

void destroiPilha(pilha* p) {
	free(p->bolo);
	free(p);
}

int inserePilha(pilha* p, char elemento) {
	if(p->topo == MAX)
		return 0; //pilha cheia

	p->bolo[p->topo] = elemento;
	p->topo++;
	return 1;
}

int removePilha(pilha* p, char* elemento) {
	p->topo--; // decrementa primeiro pois p->topo finaliza na posição 3 que não está ocupada
	if(p->topo == -1)
		return 0; //pilha vazia
	*elemento = p->bolo[p->topo];	
	return 1;
}