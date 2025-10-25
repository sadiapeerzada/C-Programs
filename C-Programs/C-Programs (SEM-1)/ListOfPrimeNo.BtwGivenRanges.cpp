#include <stdio.h>


int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int start, end;

    
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    
    for (int num = start; num <= end; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }

    printf("\n");
    return 0;
}

