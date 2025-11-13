#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Funções principais
No* criarNo(int valor);
void inserirInicio(No** inicio, int valor);
void inserirFim(No** inicio, int valor);
void remover(No** inicio, int valor);
void imprimirLista(No* inicio);
void liberarLista(No** inicio);

#endif
