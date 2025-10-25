#include <stdio.h>
struct student{
	char name[51];
	char rn[13];
	char en[9];
};
int main(){
	int n,i;
	printf("How many students : ");
	scanf(" %d", &n);
	struct student students[n];
	printf("Enter the details : \n");
	for(i=0;i<n;i++){
		printf("Student %d:\n",i+1);
		fflush(stdin);
		printf("Name : ");
		gets(students[i].name);
		printf("Roll no. : ");
		gets(students[i].rn);
		printf("Enrollment no. : ");
		gets(students[i].en);
	}
	printf("\nYour list :\n\n");
	for(i=0;i<n;i++){
		printf("Student %d:\n",i+1);
		printf("Name : ");
		puts(students[i].name);
		printf("Roll no. : ");
		puts(students[i].rn);
		printf("Enrollment no. : ");
		puts(students[i].en);
	}
}
