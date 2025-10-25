#include <stdio.h>
#include <math.h>

int main() {
    int flag = 1;
    printf("a. Rectangle\nb. Circle\nc. Triangle\nd. Square\n");
    while (flag == 1) {
        flag = 0;
        printf("Enter a choice:\n");
        char c;
        scanf(" %c", &c);  
        switch (c) {
            case 'a': {
                printf("Enter length and width:\n");
                float l, b;
                scanf("%f %f", &l, &b);
                printf("Area = %.2f\n", l * b);
                printf("Perimeter = %.2f\n", 2 * (l + b));
                break;
            }
            case 'b': {
                printf("Enter the radius:\n");
                float r;
                scanf("%f", &r);
                printf("Area = %.2f\n", M_PI * r * r); 
                printf("Circumference = %.2f\n", 2 * M_PI * r);
                break;
            }
            case 'c': {
                printf("Enter the sides of the triangle:\n");
                float x, y, z;
                scanf("%f %f %f", &x, &y, &z);
                float s = (x + y + z) / 2;
                printf("Area = %.2f\n", sqrt(s * (s - x) * (s - y) * (s - z)));
                printf("Perimeter = %.2f\n", x + y + z);
                break;
            }
            case 'd': {
                printf("Enter the side of the square:\n");
                float side;
                scanf("%f", &side);
                printf("Area = %.2f\n", side * side);
                printf("Perimeter = %.2f\n", 4 * side);
                break;
            }
            default: {
                printf("Enter a valid choice!\n");
                flag = 1; 
            }
        }
    }
    return 0;  
}

