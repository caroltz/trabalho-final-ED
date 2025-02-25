#include "lista.h"
#include <stdlib.h>
#include <stdio.h>


int inicializaLista(lista* l, int tamMax) {
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->ant = n->prox = l->sentinela = n;
	l->qtd = 0;
	l->maximo = tamMax;
	return 1;
}

void desalocaLista(lista *l) {
	Pedido elem;
	while (!vazia(l))
		removeLista(l, &elem);
	free(l->sentinela);
}


int insereLista(lista *l, Pedido pedido) {
	if (!cheia(l)) {
		
		struct node *n = (struct node*)malloc(sizeof(struct node));
		n->item = pedido;
		n->prox = l->sentinela;
		n->ant = l->sentinela->ant;
		l->sentinela->ant = n;
		n->ant->prox = n;
		
		l->qtd++;
		
		return 1;
	}
	return 0;
}

int removeLista(lista *l, Pedido* pedido) {
	if(!vazia(l)){
		struct node *n = l->sentinela->prox;
		l->sentinela->prox = n->prox;
		n->prox->ant = l->sentinela;
		*pedido = n->item;
		free(n);
		
		l->qtd--;
		
		return 1;
	}
	return 0;
} // salva no pedido o item removido da lista

int vazia(lista *l) {
	return l->qtd == 0;
}

int cheia(lista *l) {
	return l->qtd == l->maximo;
}