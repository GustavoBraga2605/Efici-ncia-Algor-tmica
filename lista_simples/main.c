#include <stdio.h>
#include "lista_simples.h" // pode-se alterar para "ia_versao.h" se quiser testar a versão IA

int main() {
    No* lista = NULL;

    printf("=== Teste de Lista Simples ===\n");

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);

    printf("Lista atual: ");
    imprimirLista(lista);

    printf("\nRemovendo o elemento 20...\n");
    remover(&lista, 20);
    imprimirLista(lista);

    printf("\nLiberando lista...\n");
    liberarLista(&lista);

    return 0;
}
