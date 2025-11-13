#include "lista_circular.h"

// Criação segura de nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Busca valor (retorna 1 se encontrado, 0 se não)
int buscarValor(No* inicio, int valor) {
    if (inicio == NULL) return 0;

    No* atual = inicio;
    do {
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    } while (atual != inicio);

    return 0;
}

// Inserção no início sem duplicatas
void inserirInicio(No** inicio, int valor) {
    if (buscarValor(*inicio, valor)) {
        printf("Valor %d já existe na lista.\n", valor);
        return;
    }

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
    printf("Valor %d inserido no início.\n", valor);
}

// Inserção no final sem duplicatas
void inserirFim(No** inicio, int valor) {
    if (buscarValor(*inicio, valor)) {
        printf("Valor %d já existe na lista.\n", valor);
        return;
    }

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
    printf("Valor %d inserido no fim.\n", valor);
}

// Remoção segura de valor
void removerValor(No** inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = *inicio, *anterior = NULL;

    do {
        if (atual->valor == valor) {
            if (anterior != NULL)
                anterior->prox = atual->prox;
            else {
                No* temp = *inicio;
                while (temp->prox != *inicio) temp = temp->prox;
                *inicio = atual->prox;
                temp->prox = *inicio;
            }

            if (atual->prox == atual)
                *inicio = NULL;

            free(atual);
            printf("Valor %d removido.\n", valor);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    } while (atual != *inicio);

    printf("Valor %d não encontrado.\n", valor);
}

// Exibição de lista circular
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

// Liberação com verificação
void liberarLista(No** inicio) {
    if (*inicio == NULL) return;

    No *atual = *inicio, *temp;
    do {
        temp = atual->prox;
        free(atual);
        atual = temp;
    } while (atual != *inicio);

    *inicio = NULL;
    printf("Memória liberada com sucesso.\n");
}
