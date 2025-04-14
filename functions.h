#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h> // For boolean types
#include <stddef.h>  // For size_t

// Define the structure for a stack node
typedef struct StackNode {
    int data;                 // Data stored in the node
    struct StackNode* next;   // Pointer to the next node
} Node;

// Define the structure for the stack
typedef struct Stack {
    StackNode* top;           // Pointer to the top of the stack
    size_t size;              // Number of elements in the stack
} Stack;

// Define the structures for the queue
typedef struct {
    node_t *front;
    node_t *rear;
    int size;
    } Queue;
    
// Function prototypes


void initializeStack(Stack* stack);
bool isStackEmpty(const Stack* stack);
void push(Stack* stack, int data);
_Bool pop(Stack* stack, int data);
_Bool peek(Stack* stack, int* elem);
void enqueue(queue_t *queue, int elem);
_Bool front(queue_t *queue, int *elem);
_Bool dequeue(queue_t *queue, int *elem);

#endif // FUNCTIONS_H