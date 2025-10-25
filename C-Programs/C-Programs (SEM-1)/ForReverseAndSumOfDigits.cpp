#include <stdio.h>

int main() {
    int number, sum = 0, reverse = 0, digit;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    while (number > 0) {
        digit = number % 10;  
        sum += digit;         
        reverse = reverse * 10 + digit;  
        number /= 10;  
    }
    
    printf("Sum of digits: %d\n", sum);
    printf("Reversed number: %d\n", reverse);
    
    return 0;
}

