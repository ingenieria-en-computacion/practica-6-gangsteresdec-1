#include "bicola.h"

int main() {
    Bicola mi_bicola;
    int valor;
    
    // Inicializar la bicola
    initialize_deque(&mi_bicola);
    
    printf("\n--- Insercion de elementos atras y al frente ---\n");
    insert_last(&mi_bicola, 20);   // [20]
    display_deque(&mi_bicola);
    
    insert_first(&mi_bicola, 10);  // [10, 20]
    display_deque(&mi_bicola);
    
    insert_last(&mi_bicola, 30);   // [10, 20, 30]
    display_deque(&mi_bicola);
    
    insert_first(&mi_bicola, 5);   // [5, 10, 20, 30]
    display_deque(&mi_bicola);
    
    printf("Tama%co actual: %d\n", 164, get_size(&mi_bicola));
    
    // Consultar elementos del frente y final sin eliminarlos
    printf("\n--- Consulta de elementos ---\n");
    if (peek_first(&mi_bicola, &valor)) {
        printf("Elemento en el frente: %d\n", valor);
    }
    
    if (peek_last(&mi_bicola, &valor)) {
        printf("Elemento en el final: %d\n", valor);
    }
    
    // Eliminar elementos
    printf("\n--- Eliminar elementos ---\n");
    if (remove_first(&mi_bicola, &valor)) {
        printf("Elemento eliminado del frente: %d\n", valor);
        display_deque(&mi_bicola);  // [10, 20, 30]
    }
    
    if (remove_last(&mi_bicola, &valor)) {
        printf("Elemento eliminado del final: %d\n", valor);
        display_deque(&mi_bicola);  // [10, 20]
    }
    
    printf("Tama%co actual: %d\n", 164, get_size(&mi_bicola));
    
    // Vaciar la bicola
    printf("Eliminando todos los elementos...\n");
    while (!is_empty(&mi_bicola)) {
        remove_first(&mi_bicola, &valor);
        printf("Eliminado: %d\n", valor);
    }
    
    printf("Bicola despues de eliminar todos los elementos:\n");
    display_deque(&mi_bicola);
    
    // Intentar eliminar de una bicola vacía
    if (!remove_first(&mi_bicola, &valor)) {
        printf("Correctamente identificado que no se puede \neliminar de una bicola vacia.\n\n");
    }
    
    
    return 0;
}