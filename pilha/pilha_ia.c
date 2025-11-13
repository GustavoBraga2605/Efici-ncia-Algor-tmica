#include "pilha.h"

// Cria nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Push
void push(No** topo, int valor) {
    No* novo = criarNo(valor);
    novo->prox = *topo;
    *topo = novo;
}

// Pop
int pop(No** topo) {
    if (*topo == NULL) return -1;
    No* temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

// Top
int top(No* topo) {
    if (topo == NULL) return -1;
    return topo->valor;
}

// isEmpty
int isEmpty(No* topo) {
    return topo == NULL;
}

// Exibir pilha
void exibirPilha(No* topo) {
    No* atual = topo;
    printf("Pilha: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Liberar memória
void liberarPilha(No** topo) {
    No* atual = *topo;
    No* temp;
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
    *topo = NULL;
}
