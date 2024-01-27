#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int frequency;
    struct Node *left, *right;
};

struct Node* createNode(char data, int frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("Character: %c, Huffman Code: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    
    char chars[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {5, 9, 12, 13, 16};

    int n = sizeof(chars) / sizeof(chars[0]);

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(chars[i], frequencies[i]);
    }

    while (n > 1) {
        
        int firstMin = 0, secondMin = 1;
        for (int i = 2; i < n; i++) {
            if (nodes[i]->frequency < nodes[firstMin]->frequency) {
                secondMin = firstMin;
                firstMin = i;
            } else if (nodes[i]->frequency < nodes[secondMin]->frequency) {
                secondMin = i;
            }
        }

        struct Node* newNode = createNode('$', nodes[firstMin]->frequency + nodes[secondMin]->frequency);
        newNode->left = nodes[firstMin];
        newNode->right = nodes[secondMin];

        
        nodes[firstMin] = newNode;
        nodes[secondMin] = nodes[n - 1];
        n--;
    }

    int arr[100], top = 0;
    printCodes(nodes[0], arr, top);

    return 0;
}
