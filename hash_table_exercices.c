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


// Function to insert a contact into the linked list
void insert(contact_t **head, const char *name, const char *addr) {
    contact_t *current = *head;

    // Check if key already exists — update the address
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            free(current->addr);  // Free old address
            current->addr = strdup(addr);  // Update with new one
            return;
        }
        current = current->next;
    }

    // Create new node and insert at the front
    contact_t *new_node = malloc(sizeof(contact_t));
    new_node->name = strdup(name);
    new_node->addr = strdup(addr);
    new_node->next = *head;
    *head = new_node;
}

// Function to look up a contact by name
char *lookup(contact_t *head, const char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head->addr;
        }
        head = head->next;
    }
    return NULL;  // Not found
}

// Function to remove a contact by name
void remove_contact(contact_t **head, const char *name) {
    contact_t *current = *head;
    contact_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // If it's the head
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            // Free memory
            free(current->name);
            free(current->addr);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
