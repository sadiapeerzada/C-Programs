#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
    int numberOfElements;

    
    numberOfElements = sizeof(arr) / sizeof(arr[0]);

    
    printf("Number of elements in the array: %d\n", numberOfElements);

    return 0;
}

