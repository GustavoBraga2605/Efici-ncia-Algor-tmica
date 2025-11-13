#include "lista_dupla.h"

int main() {
    No* lista = NULL;

    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 20);
    inserirOrdenado(&lista, 15);
    inserirOrdenado(&lista, 10); // Teste de duplicata

    exibirLista(lista);
    exibirListaReversa(lista);

    removerValor(&lista, 20);
    removerValor(&lista, 7); // inexistente

    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}
