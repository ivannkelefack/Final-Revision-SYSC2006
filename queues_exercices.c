#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  // For malloc and free
#include <stdbool.h> // For boolean types
#include <stddef.h>  // For size_t
#include <string.h>  // For memset

#include "functions.h"


int main()
{
    // Test your hash table functions here
    printf("Hash table exercises initialized.\n");
    return 0;
}

// Enqueue a new element into the queue
void enqueue(Queue *queue, int elem) {
    assert(queue != NULL);
    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node != NULL);

    new_node->data = elem;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        // If the queue is empty, both front and rear point to the new node
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        // Add the new node at the end of the queue and update the rear
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

// Get the front element of the queue without removing it
_Bool front(Queue *queue, int *elem) {
    assert(queue != NULL);
    if (queue->front == NULL) {
        // Queue is empty
        return false;
    }

    *elem = queue->front->data;
    return true;
}

// Dequeue an element from the front of the queue and return it
_Bool dequeue(Queue *queue, int *elem) {
    assert(queue != NULL);
    if (queue->front == NULL) {
        // Queue is empty
        return false;
    }

    node_t *temp = queue->front;
    *elem = temp->data;

    // Move the front pointer to the next node
    queue->front = queue->front->next;

    // If the queue becomes empty, update the rear pointer
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return true;
}



