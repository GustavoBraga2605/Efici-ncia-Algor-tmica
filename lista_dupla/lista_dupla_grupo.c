#include "lista_dupla.h"

// Criação segura de nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para novo nó.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// Inserção ordenada sem duplicatas
void inserirOrdenado(No** inicio, int valor) {
    if (buscarValor(*inicio, valor)) {
        printf("Aviso: valor %d já existe na lista.\n", valor);
        return;
    }

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
    printf("Valor %d inserido com sucesso!\n", valor);
}

// Busca por valor
No* buscarValor(No* inicio, int valor) {
    while (inicio != NULL) {
        if (inicio->valor == valor) return inicio;
        inicio = inicio->prox;
    }
    return NULL;
}

// Remoção segura
void removerValor(No** inicio, int valor) {
    No* atual = buscarValor(*inicio, valor);

    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", valor);
        return;
    }

    if (atual->ant != NULL)
        atual->ant->prox = atual->prox;
    else
        *inicio = atual->prox;

    if (atual->prox != NULL)
        atual->prox->ant = atual->ant;

    free(atual);
    printf("Valor %d removido com sucesso!\n", valor);
}

// Exibição completa
void exibirLista(No* inicio) {
    printf("Lista (início → fim): ");
    while (inicio != NULL) {
        printf("%d <-> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

// Exibição reversa
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

// Liberação de memória
void liberarLista(No** inicio) {
    No* atual = *inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL;
}
