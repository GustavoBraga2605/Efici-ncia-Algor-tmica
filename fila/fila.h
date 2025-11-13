#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Fila {
    No* frente;
    No* tras;
} Fila;

// Protótipos
Fila* criarFila();
void enqueue(Fila* f, int valor);
int dequeue(Fila* f);
int front(Fila* f);
int isEmpty(Fila* f);
void exibirFila(Fila* f);
void liberarFila(Fila* f);

#endif
