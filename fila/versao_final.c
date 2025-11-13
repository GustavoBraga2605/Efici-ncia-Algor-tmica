// Versão final revisada pelo grupo — validada no VSCode
// Ajustes: tratamento de fila vazia, liberação de memória e mensagens de depuração

#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
} Fila;

// Criação da fila
Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para fila.\n");
        exit(EXIT_FAILURE);
    }
    f->inicio = f->fim = NULL;
    return f;
}

// Inserção (enqueue)
void enfileirar(Fila* f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para nó.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    printf("Enfileirado: %d\n", valor);
}

// Remoção (dequeue)
void desenfileirar(Fila* f) {
    if (f->inicio == NULL) {
        printf("A fila está vazia. Nada a remover.\n");
        return;
    }

    No* temp = f->inicio;
    printf("Desenfileirado: %d\n", temp->valor);
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
}

// Visualizar o início da fila
int frente(Fila* f) {
    if (f->inicio == NULL) {
        printf("Fila vazia.\n");
        return -1;
    }
    return f->inicio->valor;
}

// Verificar se está vazia
int estaVazia(Fila* f) {
    return f->inicio == NULL;
}

// Impressão
void imprimir(Fila* f) {
    if (f->inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila (início -> fim): ");
    No* atual = f->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// Liberação completa
void liberarFila(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(f);
    printf("Memória da fila liberada.\n");
}

// Teste no VSCode
int main() {
    Fila* f = criarFila();

    printf("\n--- Teste de Fila (Queue) ---\n");

    enfileirar(f, 5);
    enfileirar(f, 10);
    enfileirar(f, 15);

    imprimir(f);

    desenfileirar(f);
    imprimir(f);

    printf("Frente atual: %d\n", frente(f));

    liberarFila(f);
    return 0;
}
