#include <stdio.h>
#include <stdlib.h>
#include "ia_versao.h"

Node* inserirOrdenado(Node* head, int valor) {
    Node* novo = malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;

    if (!head || valor < head->data) {
        novo->next = head;
        return novo;
    }

    Node* atual = head;
    while (atual->next && atual->next->data < valor)
        atual = atual->next;

    novo->next = atual->next;
    atual->next = novo;
    return head;
}

Node* removerValor(Node* head, int valor) {
    if (!head) return NULL;
    if (head->data == valor) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* atual = head;
    while (atual->next && atual->next->data != valor)
        atual = atual->next;

    if (atual->next) {
        Node* temp = atual->next;
        atual->next = atual->next->next;
        free(temp);
    }

    return head;
}

Node* buscarValor(Node* head, int valor) {
    while (head) {
        if (head->data == valor) return head;
        head = head->next;
    }
    return NULL;
}

void imprimirLista(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
