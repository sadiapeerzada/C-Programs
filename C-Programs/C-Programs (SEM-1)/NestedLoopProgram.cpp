#include<stdio.h>

int main() {
	int rows, cols, i, j;
	
	printf("Enter the number of rows:");
	scanf("%d", &rows);
	
	for(i=1; i<= rows; i++) {
	for(j=1; j<= rows; j++){
		printf(" ");
	}
	
	for(j=1; j<=i; j++) {
		printf("%d",j);
	}
	
	for(j=1; j<=1;j++) {
		printf(" ");
	}
	for(j=i-1; j>=1;j--) {
		printf("%d", j);
	}
	printf("\n");
}
    return 0;
}

