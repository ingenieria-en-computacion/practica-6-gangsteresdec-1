#pragma once
#include "../include/linked_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos de cola circular
// ----------------------------
#define DECLARE_CIRCULAR_QUEUE(TYPE) \
    typedef struct { \
        Node_##TYPE* front; \
        Node_##TYPE* rear; \
        size_t capacity; \
        size_t size; \
    } CircularQueue_##TYPE; \
    \
    CircularQueue_##TYPE* circular_queue_##TYPE##_create(size_t capacity); \
    void circular_queue_##TYPE##_destroy(CircularQueue_##TYPE* queue); \
    bool circular_queue_##TYPE##_enqueue(CircularQueue_##TYPE* queue, TYPE data); \
    bool circular_queue_##TYPE##_dequeue(CircularQueue_##TYPE* queue, TYPE* out); \
    bool circular_queue_##TYPE##_peek(const CircularQueue_##TYPE* queue, TYPE* out); \
    bool circular_queue_##TYPE##_is_empty(const CircularQueue_##TYPE* queue); \
    bool circular_queue_##TYPE##_is_full(const CircularQueue_##TYPE* queue); \
    size_t circular_queue_##TYPE##_size(const CircularQueue_##TYPE* queue); \
    void circular_queue_##TYPE##_print(const CircularQueue_##TYPE* queue, void (*print_fn)(TYPE));

// ----------------------------
// Macro para implementación de cola circular
// ----------------------------
#define IMPLEMENT_CIRCULAR_QUEUE(TYPE) \
    CircularQueue_##TYPE* circular_queue_##TYPE##_create(size_t capacity) { \
        if (capacity == 0) return NULL; \
        \
        CircularQueue_##TYPE* queue = malloc(sizeof(CircularQueue_##TYPE)); \
        if (!queue) return NULL; \
        \
        queue->front = queue->rear = NULL; \
        queue->capacity = capacity; \
        queue->size = 0; \
        return queue; \
    } \
    \
    void circular_queue_##TYPE##_destroy(CircularQueue_##TYPE* queue) { \
        if (!queue) return; \
        \
        if (queue->front) { \
            /* Si la cola no está vacía */ \
            if (queue->size == 1) { \
                /* Solo hay un elemento */ \
                free(queue->front); \
            } else { \
                /* Hay múltiples elementos, romper el círculo para evitar bucle infinito */ \
                Node_##TYPE* current = queue->front; \
                queue->rear->next = NULL; /* Romper el círculo */ \
                \
                while (current) { \
                    Node_##TYPE* temp = current; \
                    current = current->next; \
                    free(temp); \
                } \
            } \
        } \
        \
        free(queue); \
    } \
    \
    bool circular_queue_##TYPE##_enqueue(CircularQueue_##TYPE* queue, TYPE data) { \
        if (!queue || circular_queue_##TYPE##_is_full(queue)) return false; \
        \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        \
        if (circular_queue_##TYPE##_is_empty(queue)) { \
            /* Si la cola está vacía */ \
            queue->front = new_node; \
            queue->rear = new_node; \
            new_node->next = new_node; /* Apunta a sí mismo para crear el círculo */ \
        } else { \
            /* Si la cola ya tiene elementos */ \
            new_node->next = queue->front; /* Nuevo nodo apunta al frente */ \
            queue->rear->next = new_node; /* El último nodo apunta al nuevo */ \
            queue->rear = new_node; /* Actualizar el puntero rear */ \
        } \
        \
        queue->size++; \
        return true; \
    } \
    \
    bool circular_queue_##TYPE##_dequeue(CircularQueue_##TYPE* queue, TYPE* out) { \
        if (!queue || !out || circular_queue_##TYPE##_is_empty(queue)) return false; \
        \
        /* Guardar el valor a devolver */ \
        *out = queue->front->data; \
        \
        if (queue->front == queue->rear) { \
            /* Solo queda un elemento */ \
            free(queue->front); \
            queue->front = queue->rear = NULL; \
        } else { \
            /* Más de un elemento */ \
            Node_##TYPE* temp = queue->front; \
            queue->front = queue->front->next; /* Mover el frente al siguiente */ \
            queue->rear->next = queue->front; /* Actualizar el enlace circular */ \
            free(temp); \
        } \
        \
        queue->size--; \
        return true; \
    } \
    \
    bool circular_queue_##TYPE##_peek(const CircularQueue_##TYPE* queue, TYPE* out) { \
        if (!queue || !out || circular_queue_##TYPE##_is_empty(queue)) return false; \
        \
        *out = queue->front->data; \
        return true; \
    } \
    \
    bool circular_queue_##TYPE##_is_empty(const CircularQueue_##TYPE* queue) { \
        return !queue || queue->size == 0; \
    } \
    \
    bool circular_queue_##TYPE##_is_full(const CircularQueue_##TYPE* queue) { \
        return queue && queue->size >= queue->capacity; \
    } \
    \
    size_t circular_queue_##TYPE##_size(const CircularQueue_##TYPE* queue) { \
        return queue ? queue->size : 0; \
    } \
    \
    void circular_queue_##TYPE##_print(const CircularQueue_##TYPE* queue, void (*print_fn)(TYPE)) { \
        if (!queue || !print_fn || circular_queue_##TYPE##_is_empty(queue)) { \
            printf("[]\n"); \
            return; \
        } \
        \
        printf("["); \
        \
        Node_##TYPE* current = queue->front; \
        size_t count = 0; \
        \
        do { \
            print_fn(current->data); \
            count++; \
            current = current->next; \
            \
            if (count < queue->size) printf(", "); \
        } while (current != queue->front && count < queue->size); \
        \
        printf("]\n"); \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_CIRCULAR_QUEUE(int)
DECLARE_CIRCULAR_QUEUE(char)
DECLARE_CIRCULAR_QUEUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef CIRCULAR_QUEUE_IMPLEMENTATION
IMPLEMENT_CIRCULAR_QUEUE(int)
IMPLEMENT_CIRCULAR_QUEUE(char)
IMPLEMENT_CIRCULAR_QUEUE(float)
#endif