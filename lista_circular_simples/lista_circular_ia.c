#include "lista_circular.h"

// Cria um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Insere no início da lista circular
void inserirInicio(No** inicio, int valor) {
    No* novo = criarNo(valor);
    if (*inicio == NULL) {
        novo->prox = novo;
        *inicio = novo;
        return;
    }

    No* temp = *inicio;
    while (temp->prox != *inicio) temp = temp->prox;
    temp->prox = novo;
    novo->prox = *inicio;
    *inicio = novo;
}

// Insere no final da lista circular
void inserirFim(No** inicio, int valor) {
    No* novo = criarNo(valor);
    if (*inicio == NULL) {
        novo->prox = novo;
        *inicio = novo;
        return;
    }

    No* temp = *inicio;
    while (temp->prox != *inicio) temp = temp->prox;
    temp->prox = novo;
    novo->prox = *inicio;
}

// Remove o primeiro nó com valor correspondente
void removerValor(No** inicio, int valor) {
    if (*inicio == NULL) return;

    No *atual = *inicio, *anterior = NULL;

    do {
        if (atual->valor == valor) {
            if (anterior != NULL)
                anterior->prox = atual->prox;
            else {
                // Remoção do primeiro nó
                No* temp = *inicio;
                while (temp->prox != *inicio) temp = temp->prox;
                *inicio = atual->prox;
                temp->prox = *inicio;
            }

            if (atual == *inicio && atual->prox == *inicio)
                *inicio = NULL;

            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    } while (atual != *inicio);
}

// Exibe todos os elementos
void exibirLista(No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = inicio;
    printf("Lista circular: ");
    do {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    } while (atual != inicio);
    printf("(volta ao início)\n");
}

// Libera memória
void liberarLista(No** inicio) {
    if (*inicio == NULL) return;

    No* atual = *inicio;
    No* temp;
    do {
        temp = atual->prox;
        free(atual);
        atual = temp;
    } while (atual != *inicio);

    *inicio = NULL;
}
