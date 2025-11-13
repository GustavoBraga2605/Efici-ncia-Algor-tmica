#include "lista_simples.h"

// Criar novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Inserir em ordem crescente (versão IA)
void inserirOrdenado(No** inicio, int valor) {
    No* novo = criarNo(valor);
    if (*inicio == NULL || valor < (*inicio)->valor) {
        novo->prox = *inicio;
        *inicio = novo;
        return;
    }

    No* atual = *inicio;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Remover nó pelo valor
void removerValor(No** inicio, int valor) {
    if (*inicio == NULL) return;

    No* atual = *inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return;

    if (anterior == NULL) *inicio = atual->prox;
    else anterior->prox = atual->prox;

    free(atual);
}

// Buscar valor
No* buscarValor(No* inicio, int valor) {
    while (inicio != NULL && inicio->valor != valor) {
        inicio = inicio->prox;
    }
    return inicio;
}

// Exibir lista
void exibirLista(No* inicio) {
    printf("Lista: ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

// Liberar memória
void liberarLista(No** inicio) {
    No* atual = *inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL;
}
