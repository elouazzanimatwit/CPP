#include <stdio.h>
#include <stdlib.h>


// Function to print array elements
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    int *arr = NULL;
    int size = 0, new_size;
    int input;
    
    // Prompt user for initial number of elements
    printf("Enter initial number of elements: ");
    
    scanf("%d", &size);
    
    // TODO: Allocate memory for the array (dynamically allocate memory using malloc)
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    // TODO: Ask user to input the values into the array
    printf("Array elements:\n");

    for(int i = 0; i < size; i++){
        scanf("%d", &input);
        arr[i] = input;
    }

    // TODO: Call the function to print the array elements

    print_array(arr, size);

    // Prompt user for new array size
    printf("Enter new size for the array: ");
    scanf("%d", &new_size);
    
    // TODO: Reallocate memory for the array using realloc
    arr = (int*)realloc(arr, new_size * sizeof(int));
    
    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    // If the new size is greater, prompt the user to add more elements
    if (new_size > size) {
        printf("Enter additional %d integers:\n", new_size - size);
        // TODO: Add new elements to the array (use a for-loop)
        for(int i = size; i < new_size; i++){
            scanf("%d", &input);
            arr[i] = input;
        }
    }

    // Print updated array
    printf("Updated array elements:\n");

    // TODO: Call the function to print the updated array
    print_array(arr, new_size);

    // Free allocated memory
    free(arr);
    return 0;
}