#include <stdio.h>

int main() {
    int number, new_number = 0, digit, place = 1;

    printf("Enter a 5-digit number: ");
    scanf("%d", &number);

    while (number > 0) {
        digit = number % 10;  
        digit = (digit + 1) % 10;  
        new_number = digit * place + new_number; 
        number /= 10;  
        place *= 10;  
    }

    printf("New number by adding one to each digit: %d\n", new_number);

    return 0;
}

