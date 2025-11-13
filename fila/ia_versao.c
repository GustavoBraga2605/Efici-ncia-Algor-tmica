// Versão gerada pela IA (ChatGPT)
// Implementa uma fila usando lista encadeada simples

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void enfileirar(Fila* f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
        return;
    }
    f->fim->prox = novo;
    f->fim = novo;
}

void desenfileirar(Fila* f) {
    if (f->inicio == NULL) return;
    No* temp = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(temp);
}

void imprimir(Fila* f) {
    No* atual = f->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Fila* f = criarFila();
    enfileirar(f, 1);
    enfileirar(f, 2);
    enfileirar(f, 3);
    imprimir(f);
    desenfileirar(f);
    imprimir(f);
    return 0;
}
