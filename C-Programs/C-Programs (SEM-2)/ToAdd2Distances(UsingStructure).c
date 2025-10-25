#include <stdio.h>

struct distance {
    int feet;
    int inches;
};

int main() {
    struct distance d1, d2, total;
    printf("Enter the first distance:\n");
    printf("Feet: ");
    scanf("%d",&d1.feet);
    printf("Inches: ");
    scanf("%d",&d1.inches);

    printf("Enter the second distance:\n");
    printf("Feet: ");
    scanf("%d",&d2.feet);
    printf("Inches: ");
    scanf("%d",&d2.inches);

    total.inches = d1.inches + d2.inches;
    total.feet = d1.feet + d2.feet;

    if (total.inches>=12) {
        total.feet+=total.inches/12;
        total.inches=total.inches%12;
    }
    printf("Total distance: %d feet and %d inches", total.feet, total.inches);
}
