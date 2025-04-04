#define LINKED_LIST_IMPLEMENTATION
#include "../include/linked_list.h"
#define GENERIC_BICOLA_IMPLEMENTATION
#include "generic_bicola.h"

void print_int(int value) {
    printf("%d ", value);
}

void print_char(char value) {
    printf("%c ", value);
}

int main() {
    // Crear una bicola de enteros
    printf("\n=== Ejemplo de Bicola de enteros ===\n");
    Bicola_int* bicola_int = bicola_int_create();
    
    // Agregar elementos por ambos extremos
    bicola_int_push_back(bicola_int, 10);    // 10
    bicola_int_push_back(bicola_int, 20);    // 10, 20
    bicola_int_push_front(bicola_int, 5);    // 5, 10, 20
    bicola_int_push_front(bicola_int, 1);    // 1, 5, 10, 20
    
    // Mostrar la bicola
    printf("Despues de insertar: ");
    bicola_int_display(bicola_int, print_int);
    printf("\n");
    
    // Verificar tamaño
    printf("Tama%co de la bicola: %zu\n", 164, bicola_int_size(bicola_int));
    
    // Consultar elementos sin eliminarlos
    int front_value, back_value;
    if (bicola_int_peek_front(bicola_int, &front_value)) {
        printf("Elemento al frente: %d\n", front_value);
    }
    
    if (bicola_int_peek_back(bicola_int, &back_value)) {
        printf("Elemento al final: %d\n", back_value);
    }
    
    // Eliminar elementos por ambos extremos
    if (bicola_int_pop_front(bicola_int, &front_value)) {
        printf("Elemento eliminado del frente: %d\n", front_value);
    }
    
    if (bicola_int_pop_back(bicola_int, &back_value)) {
        printf("Elemento eliminado del final: %d\n", back_value);
    }
    
    // Mostrar la bicola después de eliminar
    printf("Bicola despues de eliminar: ");
    bicola_int_display(bicola_int, print_int);
    printf("\n");
    
    // Ejemplo con bicola de caracteres
    printf("\n=== Ejemplo de Bicola de caracteres ===\n");
    Bicola_char* bicola_char = bicola_char_create();
    
    // Agregar caracteres
    bicola_char_push_back(bicola_char, 'H');
    bicola_char_push_back(bicola_char, 'O');
    bicola_char_push_back(bicola_char, 'L');
    bicola_char_push_back(bicola_char, 'A');
    
    // Mostrar la bicola de caracteres
    printf("Bicola de caracteres: ");
    bicola_char_display(bicola_char, print_char);
    printf("\n");
    
    // Liberar memoria
    bicola_int_destroy(bicola_int);
    bicola_char_destroy(bicola_char);
    
    return 0;
}