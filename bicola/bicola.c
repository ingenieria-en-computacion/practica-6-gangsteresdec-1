#include "bicola.h"

// Inicializar la bicola
void initialize_deque(Bicola *bicola) {
    bicola->head = 0;        // En bicola lineal, head comienza en 0
    bicola->tail = -1;       // tail en -1 indica bicola vacía
    bicola->len = 0;
}

// Verificar si la bicola está vacía
bool is_empty(Bicola *bicola) {
    return bicola->len == 0;
}

// Verificar si la bicola está llena
bool is_full(Bicola *bicola) {
    return bicola->len == TAM;
}

// Obtener el tamaño actual de la bicola
int get_size(Bicola *bicola) {
    return bicola->len;
}

// Insertar elemento al frente (desplaza todos los elementos)
bool insert_first(Bicola *bicola, int valor) {
    if (is_full(bicola)) {
        printf("Error: La bicola esta llena\n");
        return false;
    }
    
    // Si es el primer elemento
    if (is_empty(bicola)) {
        bicola->head = 0;
        bicola->tail = 0;
        bicola->elementos[0] = valor;
    } else {
        // Desplazar todos los elementos una posición a la derecha
        for (int i = bicola->tail; i >= bicola->head; i--) {
            bicola->elementos[i + 1] = bicola->elementos[i];
        }
        bicola->elementos[bicola->head] = valor;
        bicola->tail++; // El final se mueve una posición
    }
    
    bicola->len++;
    return true;
}

// Insertar elemento al final
bool insert_last(Bicola *bicola, int valor) {
    if (is_full(bicola)) {
        printf("Error: La bicola esta llena\n");
        return false;
    }
    
    // Si es el primer elemento
    if (is_empty(bicola)) {
        bicola->head = 0;
        bicola->tail = 0;
        bicola->elementos[0] = valor;
    } else {
        bicola->tail++;
        bicola->elementos[bicola->tail] = valor;
    }
    
    bicola->len++;
    return true;
}

// Eliminar elemento del frente
bool remove_first(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }
    
    *valor = bicola->elementos[bicola->head];
    
    // Si solo hay un elemento
    if (bicola->head == bicola->tail) {
        bicola->head = 0;
        bicola->tail = -1;
    } else {
        bicola->head++; // Avanzamos el frente
    }
    
    bicola->len--;
    return true;
}

// Eliminar elemento del final
bool remove_last(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }
    
    *valor = bicola->elementos[bicola->tail];
    
    // Si solo hay un elemento
    if (bicola->head == bicola->tail) {
        bicola->head = 0;
        bicola->tail = -1;
    } else {
        bicola->tail--; // Retrocedemos el final
    }
    
    bicola->len--;
    return true;
}

// Consultar elemento del frente
bool peek_first(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }
    
    *valor = bicola->elementos[bicola->head];
    return true;
}

// Consultar elemento del final
bool peek_last(Bicola *bicola, int *valor) {
    if (is_empty(bicola)) {
        printf("Error: La bicola esta vacia\n");
        return false;
    }
    
    *valor = bicola->elementos[bicola->tail];
    return true;
}

// Mostrar todos los elementos de la bicola
void display_deque(Bicola *bicola) {
    if (is_empty(bicola)) {
        printf("La bicola esta vacia\n");
        return;
    }
    
    printf("Elementos de la bicola: ");
    for (int i = bicola->head; i <= bicola->tail; i++) {
        printf("%d ", bicola->elementos[i]);
    }
    printf("\n");
}