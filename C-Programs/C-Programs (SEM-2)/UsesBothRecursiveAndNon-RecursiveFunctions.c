#include <stdio.h>

// Linear Search (Non-Recursive)
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Linear Search (Recursive)
int linearSearchRec(int arr[], int n, int key, int index) {
    if (index >= n)
        return -1;
    if (arr[index] == key)
        return index;
    return linearSearchRec(arr, n, key, index + 1);
}

// Binary Search (Non-Recursive)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Binary Search (Recursive)
int binarySearchRec(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearchRec(arr, low, mid - 1, key);
    else
        return binarySearchRec(arr, mid + 1, high, key);
}

// Sort array for Binary Search
void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    printf("Sorted array for Binary Search: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[50], n, key, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    while (1) {
        printf("Menu:\n");
        printf("0. Exit\n");
        printf("1. Linear Search (Iterative)\n");
        printf("2. Linear Search (Recursive)\n");
        printf("3. Binary Search (Iterative)\n");
        printf("4. Binary Search (Recursive)\n");
        printf("Choice: ");
        scanf("%d", &choice);

        int result = -1;

        switch (choice) {
            case 1:
                result = linearSearch(arr, n, key);
                break;
            case 2:
                result = linearSearchRec(arr, n, key, 0);
                break;
            case 3:
                bubbleSort(arr, n); // Sort before binary search
                result = binarySearch(arr, n, key);
                break;
            case 4:
                bubbleSort(arr, n); // Sort before binary search
                result = binarySearchRec(arr, 0, n - 1, key);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        if (result == -1)
            printf("Key %d not found.\n", key);
        else
            printf("Key %d found at position %d.\n", key, result+1);
    }
}
