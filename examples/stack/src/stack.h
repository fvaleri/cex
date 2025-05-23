/*
 * Stack abstract data type (ADT)
 * interface for generic items.
 */

// These directives permit stack.h to be included
// more than once, which occurs when interfaces
// import other interfaces
#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

// Incomplete type used to hide the
// internal stack representation
typedef struct StackType *Stack;

// Allocate and release memory
Stack stack_create(void);
void stack_destroy(Stack s);

// Stack operations
void stack_make_empty(Stack s);
int stack_size(Stack s);
bool stack_is_empty(Stack s);
bool stack_is_full(Stack s);
void stack_push(Stack s, void *x);
void *stack_pop(Stack s);

#endif
