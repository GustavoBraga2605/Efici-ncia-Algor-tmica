// Versão gerada pela IA (ChatGPT)
// Implementa lista simplesmente encadeada de inteiros
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inserirOrdenado(Node** head, int valor) {
    Node* novo = criarNo(valor);
    if (*head == NULL || (*head)->valor >= valor) {
        novo->prox = *head;
        *head = novo;
        return;
    }
    Node* atual = *head;
    while (atual->prox != NULL && atual->prox->valor < valor)
        atual = atual->prox;
    novo->prox = atual->prox;
    atual->prox = novo;
}

void removerValor(Node** head, int valor) {
    Node* atual = *head;
    Node* anterior = NULL;
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return;
    if (anterior == NULL)
        *head = atual->prox;
    else
        anterior->prox = atual->prox;
    free(atual);
}

Node* buscar(Node* head, int valor) {
    while (head != NULL) {
        if (head->valor == valor)
            return head;
        head = head->prox;
    }
    return NULL;
}

void imprimir(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }
    printf("NULL\n");
}

int main() {
    Node* lista = NULL;
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 8);
    imprimir(lista);

    removerValor(&lista, 2);
    imprimir(lista);

    Node* n = buscar(lista, 8);
    if (n) printf("Encontrado: %d\n", n->valor);
    else printf("Não encontrado.\n");

    return 0;
}
