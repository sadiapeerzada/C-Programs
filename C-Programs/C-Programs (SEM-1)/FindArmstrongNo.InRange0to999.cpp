#include <stdio.h>

int main() {
    int number, originalNumber, remainder, result;
    
    printf("Armstrong numbers between 0 and 999 are:\n");
    
    for (number = 0; number <= 999; ++number) {
        originalNumber = number;
        result = 0;
        
        while (originalNumber != 0) {
            remainder = originalNumber % 10;  
            result += remainder * remainder * remainder;  
            originalNumber /= 10;  
        }
        
        if (result == number) {
            printf("%d\n", number);  
        }
    }
    
    return 0;
}

