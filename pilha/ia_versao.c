// Versão gerada pela IA (ChatGPT)
// Implementa uma pilha usando lista encadeada simples
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilhar(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

void desempilhar(Pilha* p) {
    if (p->topo == NULL) return;
    No* temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
}

int topo(Pilha* p) {
    if (p->topo == NULL) return -1;
    return p->topo->valor;
}

int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

void imprimir(Pilha* p) {
    No* atual = p->topo;
    printf("Topo -> ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Pilha* p = criarPilha();
    empilhar(p, 10);
    empilhar(p, 20);
    empilhar(p, 30);
    imprimir(p);
    desempilhar(p);
    imprimir(p);
    printf("Topo atual: %d\n", topo(p));
    return 0;
}
