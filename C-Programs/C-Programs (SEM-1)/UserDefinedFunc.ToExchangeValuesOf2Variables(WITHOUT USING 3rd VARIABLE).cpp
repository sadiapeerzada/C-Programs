#include <stdio.h>
void swap_without_third_var(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Before swapping: x = %d, y = %d\n", x, y);

    swap_without_third_var(&x, &y);

    printf("After swapping without using third variable: x = %d, y = %d\n", x, y);

    return 0;
}

