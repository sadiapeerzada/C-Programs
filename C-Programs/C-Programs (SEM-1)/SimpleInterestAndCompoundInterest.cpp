#include<stdio.h>
#include<math.h>

main(){
	float P,R,SI,CI,A;
	int T;
	printf("Enter the Principle: ");
	scanf("%f", &P);
	printf("number =%f",P);
	printf("Enter the Rate: ");
	scanf("%f", &R);
	printf("Enter the Time : ");
	scanf("%d", &T);
	SI=(P*R*T)/100;
	A=P*pow(1+R/100,T);
	CI=A-P;
	printf("Simple Interest: %.2f\n", SI);
	printf("Compound Interest: %.2f\n", CI);
}
