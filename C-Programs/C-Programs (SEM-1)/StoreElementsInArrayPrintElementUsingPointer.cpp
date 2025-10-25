#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Elements in the array are:\n");
    int *ptr = arr;
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}

