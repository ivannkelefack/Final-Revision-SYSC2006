#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h> // For boolean types
#include <stddef.h>  // For size_t

// Define the structure for a node
typedef struct Node {
    int data;              // Data stored in the node
    struct Stack* next;   // Pointer to the next node
} Node;

// Define the structure for the stack
typedef struct Stack {
    Node* top;           // Pointer to the top of the stack
    size_t size;        // Number of elements in the stack
} Stack;

// Define the structures for the queue
typedef struct {
    node_t *front;
    node_t *rear;
    int size;
    } Queue;

//Define the structures for the hash table 
typedef struct contact {
    char *name;
    char *addr;
    struct contact *next;
  } contact_t;
    
// Function prototypes
void initializeStack(Stack* stack); // Initialize the stack
bool isStackEmpty(const Stack* stack); // Check if the stack is empty
void push(Stack* stack, int data); // Push an element onto the stack
_Bool pop(Stack* stack, int* elem); // Pop an element from the stack
_Bool peek(Stack* stack, int* elem); // Peek at the top element of the stack
void enqueue(queue_t *queue, int elem); // Enqueue an element into the queue
_Bool front(queue_t *queue, int *elem); // Get the front element of the queue
_Bool dequeue(queue_t *queue, int *elem); // Dequeue an element from the queue
void insert(contact_t **head, const char *name, const char *addr); // Insert a contact
char *lookup(contact_t *head, const char *name); // Lookup a contact
void remove_contact(contact_t **head, const char *name); // Remove a contact

#endif // FUNCTIONS_H