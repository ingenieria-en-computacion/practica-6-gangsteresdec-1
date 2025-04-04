#define LINKED_LIST_IMPLEMENTATION
#include "../include/linked_list.h"
#define CIRCULAR_QUEUE_IMPLEMENTATION
#include "generic_circularqueue.h"

// Funciones para imprimir los distintos tipos
void print_int(int val) {
    printf("%d", val);
}

void print_char(char val) {
    printf("'%c'", val);
}

void print_float(float val) {
    printf("%.2f", val);
}

int main() {
    // Crear una cola circular de enteros con capacidad 5
    CircularQueue_int* queue_int = circular_queue_int_create(5);
    
    printf("\n=== Cola Circular de Enteros ===\n");
    printf("Estado inicial: ");
    circular_queue_int_print(queue_int, print_int);
    
    // Agregar elementos
    printf("\nAgregando elementos: 10, 20, 30...\n");
    circular_queue_int_enqueue(queue_int, 10);
    circular_queue_int_enqueue(queue_int, 20);
    circular_queue_int_enqueue(queue_int, 30);
    
    printf("Estado actual: ");
    circular_queue_int_print(queue_int, print_int);
    printf("Tama%co: %zu\n", 164, circular_queue_int_size(queue_int));
    
    // Ver el elemento frontal
    int front_value;
    if (circular_queue_int_peek(queue_int, &front_value)) {
        printf("Elemento frontal: %d\n", front_value);
    }
    
    // Quitar un elemento
    printf("\nQuitando un elemento...\n");
    int removed_value;
    if (circular_queue_int_dequeue(queue_int, &removed_value)) {
        printf("Elemento eliminado: %d\n", removed_value);
    }
    
    printf("Estado despues de quitar: ");
    circular_queue_int_print(queue_int, print_int);
    
    // Liberar memoria
    circular_queue_int_destroy(queue_int);
    
    // Probar con caracteres
    printf("\n=== Cola Circular de Caracteres ===\n");
    CircularQueue_char* queue_char = circular_queue_char_create(3);
    
    printf("Agregando caracteres: A, B, C...\n");
    circular_queue_char_enqueue(queue_char, 'A');
    circular_queue_char_enqueue(queue_char, 'B');
    circular_queue_char_enqueue(queue_char, 'C');
    
    printf("Estado: ");
    circular_queue_char_print(queue_char, print_char);
    
    printf("%cCola llena? %s\n", 168, circular_queue_char_is_full(queue_char) ? "Si" : "No");
    
    printf("Intentando agregar 'D' a una cola llena...\n");
    if (!circular_queue_char_enqueue(queue_char, 'D')) {
        printf("No se pudo agregar 'D', la cola esta llena.\n\n");
    }
    
    // Liberar memoria
    circular_queue_char_destroy(queue_char);
    
    return 0;
}