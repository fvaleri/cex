#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alias for function array pointer type
typedef int (*FuncArr[3])(void);

// Alias for struct pointer type
typedef struct sig_type *Sig;

// Custom object type
struct sig_type {
    int num;
    char name[20];
    char desc[100];
};

int main(void) {
    //puts("Hello world!");
    printf("%s\n", "Hello world!");

    /*
     * Pointers
     */

    int num = 10;
    int *ptr = &num; // address operator & gives memory address (pointer)
    printf("Original: %d\n", *ptr); // dereference operator * gives value
    *ptr = 20;
    printf("Updated: %d\n", num);

    // Using arrays
    void print_char(char c) { printf("Value: %c\n", c); }

    char str[11];
    for (unsigned int i = 0; i < 10; i++) {
        str[i] = '0' + i; // str[i] syntactic sugar for *(str + i)
        print_char(str[i]); // array-to-pointer decay
    }
    str[10] = '\0'; // null char

    // Invoke function from array
    int foo(void) { printf("%s\n", "foo"); return 0; }
    int bar(void) { printf("%s\n", "bar"); return 0; }
    int baz(void) { printf("%s\n", "baz"); return 0; }
    FuncArr funcs = { foo, bar, baz }; // function-to-pointer decay
    funcs[1]();

    /*
     * Structures
     */
    void print_sig(Sig x) { printf("Signal: %s\n", x->name); }

    Sig s1 = malloc(sizeof(struct sig_type));
    s1->num = 5;
    strcpy(s1->name, "SIGINT");
    strcpy(s1->desc, "Interrupt from keyboard");
    print_sig(s1);

    return EXIT_SUCCESS;
}
