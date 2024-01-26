#include <stdio.h>


void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void deleteElement(int arr[], int *size, int elementToDelete) {
    int found = 0;
    
    
    int i;
    for (i = 0; i < *size; i++) {
        if (arr[i] == elementToDelete) {
            found = 1;
            break;
        }
    }

    
    if (found) {
        for (int j = i; j < *size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        (*size)--;
        printf("Element %d deleted successfully.\n", elementToDelete);
    } else {
        printf("Element %d not found in the array.\n", elementToDelete);
    }
}

int main() {
    int size;
    

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    displayArray(arr, size);

    int elementToDelete;
    printf("Enter the element to delete: ");
    scanf("%d", &elementToDelete);


    deleteElement(arr, &size, elementToDelete);

 
    displayArray(arr, size);

    return 0;
}

