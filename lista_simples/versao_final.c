// Versão final revisada pelo grupo — validada no VSCode
// Ajustes: checagem de alocação, liberação completa de memória e testes de borda
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

// Cria um novo nó com verificação de alocação
Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Insere em ordem crescente
void inserirOrdenado(Node** head, int valor) {
    Node* novo = criarNo(valor);
    if (*head == NULL || (*head)->valor >= valor) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    Node* atual = *head;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
}

// Remove um nó pelo valor informado
void removerValor(Node** head, int valor) {
    if (*head == NULL) {
        printf("Lista vazia. Nada a remover.\n");
        return;
    }

    Node* atual = *head;
    Node* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *head = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}

// Busca um nó com o valor especificado
Node* buscar(Node* head, int valor) {
    while (head != NULL) {
        if (head->valor == valor)
            return head;
        head = head->prox;
    }
    return NULL;
}

// Imprime a lista
void imprimir(Node* head) {
    printf("Lista: ");
    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }
    printf("NULL\n");
}

// Libera toda a memória da lista
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

    printf("\n--- Teste Lista Simplesmente Encadeada ---\n");

    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 3);
    inserirOrdenado(&lista, 7);
    inserirOrdenado(&lista, 1);
    imprimir(lista);

    removerValor(&lista, 7);
    imprimir(lista);

    Node* n = buscar(lista, 3);
    if (n) printf("Encontrado: %d\n", n->valor);
    else printf("Não encontrado.\n");

    removerValor(&lista, 100); // Teste de valor inexistente
    imprimir(lista);

    liberarLista(&lista);
    printf("Memória liberada com sucesso.\n");

    return 0;
}
