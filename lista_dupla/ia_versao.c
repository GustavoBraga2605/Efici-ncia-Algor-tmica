// Versão gerada pela IA (ChatGPT)
// Implementa lista duplamente encadeada com inserção e remoção no início e no fim
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* ant;
    struct Node* prox;
} Node;

Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void inserirInicio(Node** head, int valor) {
    Node* novo = criarNo(valor);
    novo->prox = *head;
    if (*head != NULL)
        (*head)->ant = novo;
    *head = novo;
}

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

void removerInicio(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->prox;
    if (*head != NULL)
        (*head)->ant = NULL;
    free(temp);
}

void removerFim(Node** head) {
    if (*head == NULL) return;
    Node* atual = *head;
    while (atual->prox != NULL)
        atual = atual->prox;
    if (atual->ant != NULL)
        atual->ant->prox = NULL;
    else
        *head = NULL;
    free(atual);
}

void imprimirDireta(Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->valor);
        head = head->prox;
    }
    printf("NULL\n");
}

void imprimirReversa(Node* head) {
    if (head == NULL) return;
    while (head->prox != NULL)
        head = head->prox;
    while (head != NULL) {
        printf("%d <-> ", head->valor);
        head = head->ant;
    }
    printf("NULL\n");
}

int main() {
    Node* lista = NULL;
    inserirInicio(&lista, 10);
    inserirFim(&lista, 20);
    inserirInicio(&lista, 5);
    imprimirDireta(lista);
    imprimirReversa(lista);
    removerInicio(&lista);
    imprimirDireta(lista);
    removerFim(&lista);
    imprimirDireta(lista);
    return 0;
}
