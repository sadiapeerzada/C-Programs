#include <stdio.h>

struct complex {
    int real;
    int img;
};
struct complex add(struct complex c1, struct complex c2){
	struct complex total;
	total.img = c1.img + c2.img;
    total.real = c1.real + c2.real;
    return total;
}
int main() {
    struct complex cn1, cn2, total;
    printf("Enter the first complex no. :\n");
    printf("Real: ");
    scanf("%d",&cn1.real);
    printf("Imaginary: ");
    scanf("%d",&cn1.img);

    printf("Enter the second complex no. :\n");
    printf("Real: ");
    scanf("%d",&cn2.real);
    printf("Imaginary: ");
    scanf("%d",&cn2.img);

    total = add(cn1, cn2);

    printf("Total complex: %d + i%d", total.real, total.img);
}
