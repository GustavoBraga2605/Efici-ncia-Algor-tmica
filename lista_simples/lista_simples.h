#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó da lista simplesmente encadeada
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Protótipos das funções principais
No* criarNo(int valor);
void inserirOrdenado(No** inicio, int valor);
void removerValor(No** inicio, int valor);
No* buscarValor(No* inicio, int valor);
void exibirLista(No* inicio);
void liberarLista(No** inicio);

#endif
