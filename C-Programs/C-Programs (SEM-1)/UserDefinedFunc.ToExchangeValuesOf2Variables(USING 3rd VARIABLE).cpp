#include <stdio.h>

void swap_with_third_var(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Before swapping: x = %d, y = %d\n", x, y);

    swap_with_third_var(&x, &y);

    printf("After swapping using third variable: x = %d, y = %d\n", x, y);

    return 0;
}

