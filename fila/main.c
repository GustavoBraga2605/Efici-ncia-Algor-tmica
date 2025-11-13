#include "fila.h"

int main() {
    Fila* fila = criarFila();

    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);

    exibirFila(fila);

    printf("Frente da fila: %d\n", front(fila));

    dequeue(fila);
    exibirFila(fila);

    dequeue(fila);
    dequeue(fila);
    dequeue(fila); // fila vazia

    liberarFila(fila);

    return 0;
}
