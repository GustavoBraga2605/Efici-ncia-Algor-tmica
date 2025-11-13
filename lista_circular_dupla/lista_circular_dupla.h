#ifndef LISTA_CIRCULAR_DUPLA_H
#define LISTA_CIRCULAR_DUPLA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

// Protótipos
No* criarNo(int valor);
void inserirInicio(No** inicio, int valor);
void inserirFim(No** inicio, int valor);
void removerValor(No** inicio, int valor);
void exibirLista(No* inicio);
void exibirListaReversa(No* inicio);
void liberarLista(No** inicio);

#endif
