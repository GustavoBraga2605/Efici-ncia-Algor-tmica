#include "pilha.h"

int main() {
    No* pilha = NULL;

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    exibirPilha(pilha);

    printf("Topo da pilha: %d\n", top(pilha));

    pop(&pilha);
    exibirPilha(pilha);

    pop(&pilha);
    pop(&pilha);
    pop(&pilha); // pilha vazia

    liberarPilha(&pilha);

    return 0;
}
