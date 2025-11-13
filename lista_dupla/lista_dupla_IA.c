#include "lista_dupla.h"

// Cria um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// Insere em ordem crescente
void inserirOrdenado(No** inicio, int valor) {
    No* novo = criarNo(valor);

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    No* atual = *inicio;
    while (atual->prox != NULL && atual->valor < valor) {
        atual = atual->prox;
    }

    if (atual->valor >= valor) {
        novo->prox = atual;
        novo->ant = atual->ant;

        if (atual->ant != NULL)
            atual->ant->prox = novo;
        else
            *inicio = novo;

        atual->ant = novo;
    } else {
        atual->prox = novo;
        novo->ant = atual;
    }
}

// Remove o primeiro nó com o valor informado
void removerValor(No** inicio, int valor) {
    No* atual = *inicio;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }

    if (atual == NULL) return;

    if (atual->ant != NULL)
        atual->ant->prox = atual->prox;
    else
        *inicio = atual->prox;

    if (atual->prox != NULL)
        atual->prox->ant = atual->ant;

    free(atual);
}

// Exibe do início ao fim
void exibirLista(No* inicio) {
    printf("Lista (início → fim): ");
    while (inicio != NULL) {
        printf("%d <-> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

// Exibe do fim ao início
void exibirListaReversa(No* inicio) {
    if (inicio == NULL) return;
    No* atual = inicio;
    while (atual->prox != NULL) atual = atual->prox;

    printf("Lista (fim → início): ");
    while (atual != NULL) {
        printf("%d <-> ", atual->valor);
        atual = atual->ant;
    }
    printf("NULL\n");
}

// Libera memória
void liberarLista(No** inicio) {
    No* atual = *inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL;
}
