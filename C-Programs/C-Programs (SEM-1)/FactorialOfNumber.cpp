#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long fact = 1;  

    for (int i = 1; i <= n; ++i) {
        fact *= i;  
    }

    return fact;
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d = %llu\n", number, factorial(number));
    }

    return 0;
}

