#include "lista_simples.h"

int main() {
    No* lista = NULL;

    printf("=== TESTE LISTA SIMPLES ===\n");

    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 8);
    inserirOrdenado(&lista, 3);
    inserirOrdenado(&lista, 8); // duplicado (teste de aviso)

    exibirLista(lista);

    printf("Removendo valor 2...\n");
    removerValor(&lista, 2);
    exibirLista(lista);

    printf("Buscando valor 8...\n");
    No* resultado = buscarValor(lista, 8);
    if (resultado) printf("Valor encontrado: %d\n", resultado->valor);
    else printf("Valor não encontrado.\n");

    liberarLista(&lista);
    return 0;
}
