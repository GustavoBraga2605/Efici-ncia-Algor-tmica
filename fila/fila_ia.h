#include "fila.h"

// Criar fila
Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = f->tras = NULL;
    return f;
}

// Enqueue
void enqueue(Fila* f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (f->tras == NULL) {
        f->frente = f->tras = novo;
        return;
    }
    f->tras->prox = novo;
    f->tras = novo;
}

// Dequeue
int dequeue(Fila* f) {
    if (f->frente == NULL) return -1;
    No* temp = f->frente;
    int valor = temp->valor;
    f->frente = f->frente->prox;
    if (f->frente == NULL) f->tras = NULL;
    free(temp);
    return valor;
}

// Front
int front(Fila* f) {
    if (f->frente == NULL) return -1;
    return f->frente->valor;
}

// isEmpty
int isEmpty(Fila* f) {
    return f->frente == NULL;
}

// Exibir fila
void exibirFila(Fila* f) {
    No* atual = f->frente;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Liberar fila
void liberarFila(Fila* f) {
    No* atual = f->frente;
    No* temp;
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
    f->frente = f->tras = NULL;
    free(f);
}
