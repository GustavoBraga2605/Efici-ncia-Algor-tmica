#include "fila.h"

// Criar fila com verificação
Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (!f) {
        fprintf(stderr, "Erro ao criar fila.\n");
        exit(1);
    }
    f->frente = f->tras = NULL;
    return f;
}

// Enqueue com mensagem
void enqueue(Fila* f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro ao alocar nó.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    if (f->tras == NULL) {
        f->frente = f->tras = novo;
        printf("Enqueued %d (primeiro elemento)\n", valor);
        return;
    }
    f->tras->prox = novo;
    f->tras = novo;
    printf("Enqueued %d\n", valor);
}

// Dequeue com validação
int dequeue(Fila* f) {
    if (f->frente == NULL) {
        printf("Dequeue falhou: fila vazia\n");
        return -1;
    }
    No* temp = f->frente;
    int valor = temp->valor;
    f->frente = f->frente->prox;
    if (f->frente == NULL) f->tras = NULL;
    free(temp);
    printf("Dequeued %d\n", valor);
    return valor;
}

// Front
int front(Fila* f) {
    if (f->frente == NULL) {
        printf("Fila vazia\n");
        return -1;
    }
    return f->frente->valor;
}

// isEmpty
int isEmpty(Fila* f) {
    return f->frente == NULL;
}

// Exibir fila
void exibirFila(Fila* f) {
    No* atual = f->frente;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Liberar fila
void liberarFila(Fila* f) {
    No* atual = f->frente;
    No* temp;
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
    f->frente = f->tras = NULL;
    free(f);
    printf("Fila liberada.\n");
}
