#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

// Protótipos
No* criarNo(int valor);
void inserirOrdenado(No** inicio, int valor);
void removerValor(No** inicio, int valor);
void exibirLista(No* inicio);
void exibirListaReversa(No* inicio);
void liberarLista(No** inicio);
No* buscarValor(No* inicio, int valor);

#endif
