#include<stdio.h>

main(){
	float a,b,c;
	printf("Enter the lenght of all three sides in descending order :\n"); 
	scanf("%f %f %f", &a, &b, &c);
	if(a<b||a<c){
		printf(" not valid \n please enter in descending order");
	}
	else{
		if(a<(b+c)){
			if((a*a)==(b*b+c*c))
			printf("Right Angled Triangle!");
			else if((a*a)>(b*b+c*c))
			printf("Obtuse Angled Triangle!");
			else
			printf("Acute Angled Triangle!");
		}
		else{
		printf("Not a triangle!");
		}
	}
}
