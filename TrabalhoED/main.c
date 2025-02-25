#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

#define MAX 50

#define NUMCAMADAS 3

//frases que correspondem às comunicações com o cliente:

#define boasVindas "Ola! Seja bem vindo(a) a nossa loja de bolos! Quantos pedidos gostaria de fazer?\n"

#define numExcedido "Nosso numero de pedidos é sempre maior do que 0 e no maximo 50! Por favor, digite uma outra quantia!\n"

#define baseInvalida "Nao trabalhamos com o sabor de base escolhido! Por favor, escolha outro!\n"

#define coberturaInvalida "Nao trabalhamos com o sabor de cobertura escolhido! Por favor, escolha outro!\n"

#define enfeiteInvalido "Nao trabalhamos com o enfeite escolhido! Por favor, escolha outro!\n"

#define BASE "Sabores de bases para bolo disponiveis:\n1. Chocolate -> digite C\n2. Baunilha -> digite B\n3. Red Velvet -> digite R\n"

#define COBERTURA "Sabores de cobertura para bolo disponiveis:\n1. Brigadeiro -> digite B\n2. Prestigio -> digite P\n3. Morango-> digite M\n4. Ninho -> digite N\n"

#define ENFEITE "Enfeites para bolo disponiveis:\n1. Granulado -> digite G\n2. Chantilly -> digite C\n3. Pasta americana -> digite P\n"

#define escolhaPedido "Vamos escolher o pedido de numero %d!\n"

#define fimPedidos "Todos os pedidos foram entregues!\n"

#define boloPronto "O bolo de numero %d esta pronto! Aproveite!!\n"

int baseValida (char elem); // retorna 1 quando valido
int coberturaValida (char elem); // retorna 1 quando valido
int enfeiteValido (char elem); // retorna 1 quando valido
int numPedidosValido (int qtd); // retorna 1 quando valido
void recebePedidos (lista* l, int qtd); // recebe todos os pedidos e os coloca em uma lista 
void entregarPedido (pilha* p); // entrega pedido por pedido, removendo um por um da lista
//e preparando o bolo correspondente (pilha), ao fim, imprime para cada pedido 2 linhas
//pontinhadas e entre elas as camadas do bolo na ordem em que é finalizado.

int main () {
	
	int qtdPedidos=0;
	
	printf(boasVindas);
	scanf("%d", &qtdPedidos);
	while (!numPedidosValido(qtdPedidos)) {
		printf(numExcedido);
		scanf("%d", &qtdPedidos);
	} //solicita uma nova quantidade de pedidos até que o usuário digite um valor válido
	
	lista l;
	inicializaLista(&l, MAX);
	recebePedidos(&l, qtdPedidos);

	//Processo de produção dos bolos:
	for(int i = 0; i < qtdPedidos; i++){
		
		pilha* p = inicializaPilha(NUMCAMADAS);
		Pedido bolinho;

		//seleciona o pedido, que fica salvo na variável "bolinho"
		removeLista(&l, &bolinho);
		
		//insere cada camada do bolo na pilha
		inserePilha(p, bolinho.base);
		inserePilha(p, bolinho.cobertura);
		inserePilha(p, bolinho.enfeite);

		//remove todos os elementos da pilha, imprimindo as camadas do bolo pronto
		//como se fosse o processo de produzi-lo
		printf(boloPronto, i+1);
		entregarPedido(p);
		destroiPilha(p);		
	}

	desalocaLista(&l);

	printf(fimPedidos);	
	
	return 0;
	
}

void recebePedidos (lista* l, int qtd) {
	
	char base, cobertura, enfeite;
	Pedido pedido;
	
	for (int i=1; i<=qtd; i++) {
		
		printf(escolhaPedido, i);

		//para todos os itens irá pedir para o usuário digitar novamente caso
		//a entrada seja inválida, para ser válida é preciso que corresponda
		//aos itens disponíveis e esteja em maiúsculo
		
		printf(BASE);
		scanf("\n%c", &base);
		while (!baseValida(base)) {
			printf(baseInvalida);
			scanf("\n%c", &base);
		}
		pedido.base = base;
		
		printf(COBERTURA);
		scanf("\n%c", &cobertura);
		while (!coberturaValida(cobertura)) {
			printf(coberturaInvalida);
			scanf("\n%c", &cobertura);
		}
		pedido.cobertura = cobertura;
		
		printf(ENFEITE);
		scanf("\n%c", &enfeite);
		while (!enfeiteValido(enfeite)) {
			printf(enfeiteInvalido);
			scanf("\n%c", &enfeite);
		}
		pedido.enfeite = enfeite;

		//ao coletar os 3 dados necessários para preparar o bolo
		//o pedido é inserido na lista
		
		insereLista(l, pedido);
	}
}

int baseValida (char base) {
	if (base == 'C' || base == 'B' || base == 'R')
		return 1;
	else
		return 0;
}

int coberturaValida (char cobertura) {
	if (cobertura == 'B' || cobertura == 'P' || cobertura == 'M' || cobertura == 'N')
		return 1;
	else
		return 0;
}

int enfeiteValido (char enfeite) {
	if (enfeite == 'G' || enfeite == 'C' || enfeite == 'P')
		return 1;
	else
		return 0;
}

int numPedidosValido (int qtd) {
	return (qtd<=50 && qtd>0 );
}

void entregarPedido (pilha* p){
	printf("-----------------\n");
	char e;
	removePilha(p, &e);
	switch(e){
		case 'G':
			printf("GRANULADO\n");
			break;
		case 'C':
			printf("CHANTILLY\n");
			break;
		case 'P':
			printf("PASTA AMERICANA\n");
			break;
	}
	removePilha(p, &e);
	switch(e){
		case 'B':
			printf("BRIGADEIRO\n");
			break;
		case 'P':
			printf("PRESTIGIO\n");
			break;
		case 'M':
			printf("MORANGO\n");
			break;
		case 'N':
			printf("NINHO\n");
			break;
	}
	removePilha(p, &e);
	switch(e){
		case 'C':
			printf("CHOCOLATE\n");
			break;
		case 'B':
			printf("BAUNILHA\n");
			break;
		case 'R':
			printf("RED VELVET\n");
			break;
	}
	printf("-----------------\n");
}