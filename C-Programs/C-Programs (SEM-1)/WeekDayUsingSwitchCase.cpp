#include <stdio.h>

int main() {
    int digit;
    printf("Enter a digit (1 to 7): ");
    scanf("%d", &digit);

    switch (digit) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Error: Please enter a digit between 1 and 7.\n");
    }

    return 0;
}

