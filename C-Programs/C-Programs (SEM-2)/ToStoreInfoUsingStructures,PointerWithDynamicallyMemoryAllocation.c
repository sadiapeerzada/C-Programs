#include <stdio.h>
#include <stdlib.h>
struct student{
	char name[51];
	int rn;
};
int main(){
	typedef struct student stype;
	stype *students;
	int n,i;
	printf("How many students : ");
	scanf(" %d",&n);
	students=(stype *)malloc(n*sizeof(stype));
	for(i=0;i<n;i++){
		printf("Student %d:\n",i+1);
		fflush(stdin);
		printf("Name : ");
		gets(students[i].name);
		printf("Roll no. : ");
		scanf("%d",&students[i].rn);
	}
	printf("\nEntered details :\n");
	for(i=0;i<n;i++){
		printf("Student %d:\n",i+1);
		printf("Name : %s\n",students[i].name);
		printf("Roll no. : %d\n",students[i].rn);
	}
}