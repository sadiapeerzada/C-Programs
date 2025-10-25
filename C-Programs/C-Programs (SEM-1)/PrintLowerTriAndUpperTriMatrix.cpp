#include <stdio.h>

int main() {
    int n = 3;
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    printf("Lower Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", i >= j ? matrix[i][j] : 0);
        }
        printf("\n");
    }

    printf("\nUpper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", i <= j ? matrix[i][j] : 0);
        }
        printf("\n");
    }

    return 0;
}

