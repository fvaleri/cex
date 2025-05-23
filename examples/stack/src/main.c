#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// A variable of type "void *" can hold any pointer to an object
void *memdup(const void *src, size_t size) {
    void *p = malloc(size);
    if (p)
        memcpy(p, src, size);
    return p;
}

int *create_int(int i) {
    return memdup(&i, sizeof(i));
}

int main(void) {
    Stack s1, s2;
    int *p;

    s1 = stack_create();
    s2 = stack_create();

    p = create_int(1);
    stack_push(s1, p);

    p = create_int(2);
    stack_push(s1, p);

    printf("Stack size %d for s1\n", stack_size(s1));

    p = stack_pop(s1);
    printf("Popped %d from s1\n", *p);
    stack_push(s2, p);

    p = stack_pop(s1);
    printf("Popped %d from s1\n", *p);
    stack_push(s2, p);

    printf("Stack size %d for s1\n", stack_size(s1));

    stack_destroy(s1);

    while (!stack_is_empty(s2)) {
        p = stack_pop(s2);
        printf("Popped %d from s2\n", *p);
        // Client owns data so it must free momory
        free(p);
    }

    p = create_int(3);
    stack_push(s2, p);
    free(stack_pop(s2));

    stack_make_empty(s2);
    if (stack_is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    stack_destroy(s2);

    return 0;
}
