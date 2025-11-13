#include "lista_circular_dupla.h"

int main() {
    No* lista = NULL;

    inserirInicio(&lista, 10);
    inserirFim(&lista, 20);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 15);

    exibirLista(lista);
    exibirListaReversa(lista);

    removerValor(&lista, 10);
    removerValor(&lista, 25); // inexistente

    exibirLista(lista);
    liberarLista(&lista);

    return 0;
}
