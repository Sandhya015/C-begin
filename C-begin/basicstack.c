#include<stdio.h>
#include<stdlib.h> 

int *stack;
int top = -1;
int size;

void createStack()
{
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    stack = (int *)malloc(size * sizeof(int));
    if(stack == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Stack of size %d created successfully\n", size);
}

void push()
{
    int x;
    if(top == size - 1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        printf("Enter the element to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for(i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    createStack();
    do
    {
        printf("\nEnter your choice:\n1: Push\n2: Pop\n3: Peek\n4: Display\n0: Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while(ch != 0);
    free(stack); 
    return 0;
}

