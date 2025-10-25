#include<stdio.h>

main(){
	int a=10,b=20,c;
	int temp=a;
	printf("a=%d\nb=%d\n",a,b);
	a=b;
	b=temp;
	printf("Exchanged values with temp var:\n");
	printf("a=%d\nb=%d\n",a,b);
	printf("-----\n");
	a=50,b=100;
	printf("a=%d\nb=%d\n",a,b);
	a+=b;
	b=a-b;
	a=a-b;
	printf("Exchanged values without temp var : \n");
	printf("a=%d\nb=%d",a,b);
}
