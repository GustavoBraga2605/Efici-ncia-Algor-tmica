// Versão final revisada pelo grupo — validada no VSCode
// Ajustes: checagem de alocação, tratamento de pilha vazia, e função de liberação de memória

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Estrutura principal da pilha
typedef struct {
    No* topo;
} Pilha;

// Criação da pilha
Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para pilha.\n");
        exit(EXIT_FAILURE);
    }
    p->topo = NULL;
    return p;
}

// Insere elemento no topo (push)
void empilhar(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para nó.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    printf("Empilhado: %d\n", valor);
}

// Remove elemento do topo (pop)
void desempilhar(Pilha* p) {
    if (p->topo == NULL) {
        printf("A pilha está vazia. Nada a desempilhar.\n");
        return;
    }
    No* temp = p->topo;
    p->topo = p->topo->prox;
    printf("Desempilhado: %d\n", temp->valor);
    free(temp);
}

// Retorna o elemento no topo
int topo(Pilha* p) {
    if (p->topo == NULL) {
        printf("Pilha vazia.\n");
        return -1;
    }
    return p->topo->valor;
}

// Verifica se está vazia
int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

// Imprime pilha completa
void imprimir(Pilha* p) {
    if (p->topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha (topo -> base): ");
    No* atual = p->topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// Libera toda a memória da pilha
void liberarPilha(Pilha* p) {
    No* atual = p->topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(p);
    printf("Memória da pilha liberada.\n");
}

// Função principal de teste
int main() {
    Pilha* p = criarPilha();

    printf("\n--- Teste de Pilha (Stack) ---\n");

    empilhar(p, 10);
    empilhar(p, 20);
    empilhar(p, 30);

    imprimir(p);

    desempilhar(p);
    imprimir(p);

    printf("Topo atual: %d\n", topo(p));

    liberarPilha(p);
    return 0;
}
