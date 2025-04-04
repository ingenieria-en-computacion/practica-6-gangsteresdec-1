#include "circularqueue.h"

int main() {
    cqueue q;
    
    // Inicializar la cola
    init(&q);
    
    printf("\nEstado inicial de la cola circular:\n");
    print(&q);
    
    // Agregar elementos a la cola
    printf("\nAgregando elementos a la cola circular...\n");
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    
    // Mostrar el estado de la cola
    print(&q);
    
    // Mostrar el primer y último elemento
    printf("Primer elemento: %c\n", first(&q));
    printf("Ultimo elemento: %c\n", last(&q));
    
    // Eliminar un elemento
    printf("\nEliminando un elemento...\n");
    dequeue(&q);
    print(&q);
    
    // Agregar más elementos
    printf("\nAgregando mas elementos...\n");
    enqueue(&q, 'D');
    enqueue(&q, 'E');
    print(&q);// Mostrar estado final
    
    // Vaciar la cola
    printf("\nVaciando la cola circular...\n");
    empty(&q);
    print(&q);// Verificar que esté vacía
    printf("\n");
    
    return 0;
}