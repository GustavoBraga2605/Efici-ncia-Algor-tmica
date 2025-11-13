#include "lista_circular.h"

int main() {
    No* lista = NULL;

    inserirInicio(&lista, 10);
    inserirFim(&lista, 20);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 15);
    inserirFim(&lista, 10); // duplicata

    exibirLista(lista);

    removerValor(&lista, 15);
    removerValor(&lista, 7); // inexistente
    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}
