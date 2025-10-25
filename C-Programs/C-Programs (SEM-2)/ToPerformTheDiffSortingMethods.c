#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insertion Sort for integers
void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Sorted (Insertion Sort): ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort for characters
void bubbleSortChar(char arr[], int n) {
    int i, j;
    char temp;
    int swapped;
    for(i = 0; i < n - 1; i++) {
        swapped = 0;
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
    printf("Sorted (Bubble Sort): ");
    for(i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// Selection Sort for integers
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for(i = 0; i < n - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    printf("Sorted (Selection Sort): ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Quick Sort for characters
void quickSortChar(char arr[], int low, int high) {
    if(low < high) {
        char pivot = arr[high];
        int i = low - 1;
        char temp;
        for(int j = low; j < high; j++) {
            if(arr[j] <= pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

int main() {
    int choice;
    printf("Choose sorting algorithm:\n");
    printf("1. Insertion Sort (integers)\n");
    printf("2. Bubble Sort (characters)\n");
    printf("3. Selection Sort (integers)\n");
    printf("4. Quick Sort (characters)\n");
    scanf("%d", &choice);

    if(choice == 1 || choice == 3) {
        int arr[50], n, i;
        printf("Enter number of elements: ");
        scanf("%d", &n);
        printf("Enter %d integers: ", n);
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        if(choice == 1)
            insertionSort(arr, n);
        else
            selectionSort(arr, n);
    }
    else if(choice == 2 || choice == 4) {
        char arr[50];
        printf("Enter a string (without spaces): ");
        scanf("%s", arr);
        int len = strlen(arr);

        if(choice == 2)
            bubbleSortChar(arr, len);
        else {
            quickSortChar(arr, 0, len - 1);
            printf("Sorted (Quick Sort): ");
            for(int i = 0; i < len; i++)
                printf("%c ", arr[i]);
            printf("\n");
        }
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
