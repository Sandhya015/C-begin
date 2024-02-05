#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}

int findMin(Stack *stack) {
    int min = stack->arr[0];
    for (int i = 1; i <= stack->top; ++i) {
        if (stack->arr[i] < min) {
            min = stack->arr[i];
        }
    }
    return min;
}

int findMax(Stack *stack) {
    int max = stack->arr[0];
    for (int i = 1; i <= stack->top; ++i) {
        if (stack->arr[i] > max) {
            max = stack->arr[i];
        }
    }
    return max;
}

int main() {
    Stack stack;
    initialize(&stack);

    int n, value;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("Minimum element in the stack: %d\n", findMin(&stack));
    printf("Maximum element in the stack: %d\n", findMax(&stack));

    return 0;
}

