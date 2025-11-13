// Versão final revisada pelo grupo — validada no VSCode
// Ajustes: checagem de alocação, liberação completa de memória e mensagens mais informativas
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* ant;
    struct Node* prox;
} Node;

// Criação segura de nó
Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

// Insere no início
void inserirInicio(Node** head, int valor) {
    Node* novo = criarNo(valor);
    novo->prox = *head;
    if (*head != NULL)
        (*head)->ant = novo;
    *head = novo;
}

// Insere no final
void inserirFim(Node** head, int valor) {
    Node* novo = criarNo(valor);
    if (*head == NULL) {
        *head = novo;
        return;
    }
    Node* atual = *head;
    while (atual->prox != NULL)
        atual = atual->prox;
    atual->prox = novo;
    novo->ant = atual;
}

// Remove do início
void removerInicio(Node** head) {
    if (*head == NULL) {
        printf("Lista vazia. Nada a remover.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->prox;
    if (*head != NULL)
        (*head)->ant = NULL;
    free(temp);
}

// Remove do fim
void removerFim(Node** head) {
    if (*head == NULL) {
        printf("Lista vazia. Nada a remover.\n");
        return;
    }
    Node* atual = *head;
    while (atual->prox != NULL)
        atual = atual->prox;

    if (atual->ant != NULL)
        atual->ant->prox = NULL;
    else
        *head = NULL;

    free(atual);
}

// Imprime do início ao fim
void imprimirDireta(Node* head) {
    printf("Lista (direta): ");
    while (head != NULL) {
        printf("%d <-> ", head->valor);
        head = head->prox;
    }
    printf("NULL\n");
}

// Imprime do fim ao início
void imprimirReversa(Node* head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node* atual = head;
    while (atual->prox != NULL)
        atual = atual->prox;

    printf("Lista (reversa): ");
    while (atual != NULL) {
        printf("%d <-> ", atual->valor);
        atual = atual->ant;
    }
    printf("NULL\n");
}

// Libera toda a memória
void liberarLista(Node** head) {
    Node* atual = *head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *head = NULL;
}

int main() {
    Node* lista = NULL;

    printf("\n--- Teste Lista Duplamente Encadeada ---\n");

    inserirInicio(&lista, 10);
    inserirFim(&lista, 20);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 30);

    imprimirDireta(lista);
    imprimirReversa(lista);

    removerInicio(&lista);
    imprimirDireta(lista);

    removerFim(&lista);
    imprimirDireta(lista);

    liberarLista(&lista);
    printf("Memória liberada com sucesso.\n");

    return 0;
}
