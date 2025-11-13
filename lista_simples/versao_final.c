#include "lista_simples.h"

// Cria um novo nó com verificação de erro
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Inserção em ordem crescente com tratamento de duplicatas
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

    // Evita duplicatas
    if (atual->prox != NULL && atual->prox->valor == valor) {
        printf("Aviso: valor %d já existe na lista.\n", valor);
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Remoção com mensagem de validação
void removerValor(No** inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vazia, nada a remover.\n");
        return;
    }

    No* atual = *inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", valor);
        return;
    }

    if (anterior == NULL)
        *inicio = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    printf("Valor %d removido com sucesso.\n", valor);
}

// Busca simples
No* buscarValor(No* inicio, int valor) {
    while (inicio != NULL) {
        if (inicio->valor == valor) return inicio;
        inicio = inicio->prox;
    }
    return NULL;
}

// Exibição da lista
void exibirLista(No* inicio) {
    printf("Lista: ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

// Liberação completa da lista
void liberarLista(No** inicio) {
    No* atual = *inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL;
}
