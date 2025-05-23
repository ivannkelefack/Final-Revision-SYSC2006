
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  // For malloc and free
#include <stdbool.h> // For boolean types
#include <stddef.h>  // For size_t
#include <string.h>  // For memset

#include "functions.h"


int main()
{
    // Test your stack functions here
    printf("Stack exercises initialized.\n");
    return 0;
}

void initializeStack(Stack *stack)
{
    struct Stack *stack = malloc(sizeof(Stack));
    assert(stack != NULL);

    stack->top = NULL;
    stack->size = 0;
}

bool isStackEmpty(const Stack *stack)
{
    struct Stack *stack = malloc(sizeof(Stack));
    assert(stack != NULL);

    if (stack->size == 0 && stack->top == NULL)
    {
        return true;
    }

    return false;
}

void push(Stack *stack, int data)
{
    assert(stack != NULL);
    struct Node *newnode = malloc(sizeof(Node));
    assert(newnode != NULL);
    newnode->data = data;
    newnode->next = stack->top;
    stack->top = newnode;
    stack->size += 1;
}

_Bool pop(Stack *stack, int *elem)
{
    assert(stack != NULL);
    if (stack->size == 0 && stack->top == NULL)
    {
        return false;
    }

    *elem = stack->top->data;
    Node *to_remove = stack->top;
    stack->top = to_remove->next;
    free(to_remove);
    stack->size -= 1;
    return true;
}

_Bool peek(Stack *stack, int *elem)
{
    assert(stack != NULL);
    if (stack->size == 0)
    {
        return false;
    }
    *elem = stack->top->data;
    return true;
}
