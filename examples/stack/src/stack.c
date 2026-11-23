/*
 * Implementation of a
 * stack for generic items.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Implemented as a linked list
struct stack_type {
    int count;
    struct node {
        void *data;
        struct node *next;
    } *top;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack stack_create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
    s->count = 0;
    s->top = NULL;
    return s;
}

// Calls make_empty to release the memory
// occupied by the nodes in the linked list
void stack_destroy(Stack s) {
    stack_make_empty(s);
    free(s);
}

// Frees list nodes but not the data they point to;
// the caller must free their data before calling this
void stack_make_empty(Stack s) {
    while (!stack_is_empty(s))
        stack_pop(s);
}

int stack_size(Stack s) {
    return s->count;
}

bool stack_is_empty(Stack s) {
    return s->top == NULL;
}

// Since the stack is implemented as a linked list,
// it's never really "full". It can grow as long
// as malloc succeed.
bool stack_is_full(Stack s) {
    (void) s; // Silent unused param
    return false;
}

void stack_push(Stack s, void *x) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");
    new_node->data = x;
    new_node->next = s->top;
    s->top = new_node;
    s->count++;
}

void *stack_pop(Stack s) {
    struct node *old_top;
    void *data;

    if (stack_is_empty(s))
        terminate("Error in pop: stack is empty.");

    old_top = s->top;
    data = old_top->data;
    s->top = old_top->next;
    s->count--;
    free(old_top);

    return data;
}
