#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    
    struct Node* myNode = (struct Node*)malloc(sizeof(struct Node));
    myNode->data = 42;
    myNode->next = NULL;
    myNode->prev = NULL;

    printf("Memory address of myNode: %p\n", (void*)myNode);

    free(myNode);

    return 0;
}

