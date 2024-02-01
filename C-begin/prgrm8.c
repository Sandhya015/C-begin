#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void printList(struct Node* head) {
   
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    
    int value;
    
    struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node));
    
    
    printf("Enter data for the first node: ");
    scanf("%d", &value);
    firstNode->data = value;
    firstNode->next = NULL;
    firstNode->prev = NULL;

    
    struct Node* current = firstNode;

    
    for (int i = 0; i < 2; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        
        printf("Enter data for the next node: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        current->next = newNode;
        newNode->prev = current;

       
        current = newNode;
    }

    
    printf("Doubly Linked List: ");
    printList(firstNode);

   
    while (firstNode != NULL) {
        struct Node* temp = firstNode;
        firstNode = firstNode->next;
        free(temp);
    }

    return 0;
}

