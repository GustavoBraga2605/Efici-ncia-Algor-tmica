#include "lista_circular_dupla.h"

// Criação de nó com checagem de memória
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = novo->ant = NULL;
    return novo;
}

// Inserir no início
void inserirInicio(No** inicio, int valor) {
    No* novo = criarNo(valor);
    if (*inicio == NULL) {
        novo->prox = novo->ant = novo;
        *inicio = novo;
        printf("Inserido %d como primeiro elemento.\n", valor);
        return;
    }

    No* ultimo = (*inicio)->ant;
    novo->prox = *inicio;
    novo->ant = ultimo;
    ultimo->prox = novo;
    (*inicio)->ant = novo;
    *inicio = novo;

    printf("Inserido %d no início da lista.\n", valor);
}

// Inserir no fim
void inserirFim(No** inicio, int valor) {
    if (*inicio == NULL) {
        inserirInicio(inicio, valor);
        return;
    }

    No* novo = criarNo(valor);
    No* ultimo = (*inicio)->ant;
    novo->prox = *inicio;
    novo->ant = ultimo;
    ultimo->prox = novo;
    (*inicio)->ant = novo;

    printf("Inserido %d no final da lista.\n", valor);
}

// Remover valor com validação
void removerValor(No** inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = *inicio;
    do {
        if (atual->valor == valor) {
            if (atual->prox == atual) {
                free(atual);
                *inicio = NULL;
                printf("Valor %d removido. Lista agora está vazia.\n", valor);
                return;
            }

            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            if (atual == *inicio)
                *inicio = atual->prox;

            free(atual);
            printf("Valor %d removido.\n", valor);
            return;
        }
        atual = atual->prox;
    } while (atual != *inicio);

    printf("Valor %d não encontrado.\n", valor);
}

// Exibir lista
void exibirLista(No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = inicio;
    printf("Lista (sentido direto): ");
    do {
        printf("%d <-> ", atual->valor);
        atual = atual->prox;
    } while (atual != inicio);
    printf("(volta ao início)\n");
}

// Exibir reverso
void exibirListaReversa(No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = inicio->ant;
    printf("Lista (reversa): ");
    do {
        printf("%d <-> ", atual->valor);
        atual = atual->ant;
    } while (atual != inicio->ant);
    printf("(volta ao fim)\n");
}

// Liberação com mensagem
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
    printf("Memória liberada com sucesso.\n");
}
