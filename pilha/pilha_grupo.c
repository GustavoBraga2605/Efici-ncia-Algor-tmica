#include "pilha.h"

// Cria nó com verificação
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Push com mensagem
void push(No** topo, int valor) {
    No* novo = criarNo(valor);
    novo->prox = *topo;
    *topo = novo;
    printf("Push: %d\n", valor);
}

// Pop com validação
int pop(No** topo) {
    if (*topo == NULL) {
        printf("Pop falhou: pilha vazia\n");
        return -1;
    }
    No* temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    printf("Pop: %d\n", valor);
    return valor;
}

// Top
int top(No* topo) {
    if (topo == NULL) {
        printf("Pilha vazia\n");
        return -1;
    }
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
    while (atual) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Liberar memória
void liberarPilha(No** topo) {
    No* atual = *topo;
    No* temp;
    while (atual) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
    *topo = NULL;
    printf("Pilha liberada.\n");
}
