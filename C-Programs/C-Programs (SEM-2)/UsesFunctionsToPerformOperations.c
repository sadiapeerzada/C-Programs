#include <stdio.h>
#include <stdlib.h>
#define N 25
int a[N],n=0;

void create(){
	printf("How many elements (Max 25) : ");
	scanf(" %d", &n);
	printf("Enter the elements :\n");
	int i;
	for(i=0;i<n;i++)
		scanf(" %d", &a[i]);
}

void insert(int index){
	int i;
	for(i=n-1;i>=index;i--)
		a[i+1]=a[i];
	printf("Enter element : ");
	scanf(" %d", &a[index]);
	printf("Inserted!\n");
	n++;
}

void del(int index){
	int i;
	for(i=index;i<n-1;i++)
		a[i]=a[i+1];
	printf("Deleted!\n");
	n--;
}

void display(){
	printf("Current Array :\n");
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

main(){
	int choice;
	create();
	display();
	while(1){
		printf("Menu :\n");
		printf("1. Insert\n2. Delete\n");
		printf("3. Display\n4. Exit\n");
		scanf(" %d", &choice);
		switch(choice){
			case 1:
				if(n>=N){
					printf("No space left!\n");
					break;
				}
				printf("Position: ");
				int p1;
				scanf(" %d", &p1);
				if(p1<=n+1 && p1>=1)
					insert(p1-1);
				else printf("Enter a valid position!\n");
				break;
			case 2:
				if(n<=0){
					printf("Already empty!\n");
					break;
				}
				printf("Position: ");
				int p2;
				scanf(" %d", &p2);
				if(p2<=n && p2>=1)
					del(p2-1);
				else printf("Enter a valid position!\n");
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Enter a valid choice!\n");
		}
	}
}