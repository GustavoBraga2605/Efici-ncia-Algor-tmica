#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

// Protótipos das funções
No* criarNo(int valor);
void inserirInicio(No** inicio, int valor);
void inserirFim(No** inicio, int valor);
void removerValor(No** inicio, int valor);
void exibirLista(No* inicio);
void liberarLista(No** inicio);
int buscarValor(No* inicio, int valor);

#endif
