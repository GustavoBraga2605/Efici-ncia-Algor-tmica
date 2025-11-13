#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

// Protótipos
No* criarNo(int valor);
void push(No** topo, int valor);
int pop(No** topo);
int top(No* topo);
int isEmpty(No* topo);
void liberarPilha(No** topo);
void exibirPilha(No* topo);

#endif
