#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} CharStack;

void initialize(CharStack *stack) {
    stack->top = -1;
}

void push(CharStack *stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

char pop(CharStack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}

void reverseString(char *input) {
    int length = strlen(input);
    CharStack stack;
    initialize(&stack);

    for (int i = 0; i < length; ++i) {
        push(&stack, input[i]);
    }

    for (int i = 0; i < length; ++i) {
        input[i] = pop(&stack);
    }
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

   
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}

