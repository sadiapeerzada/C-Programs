#include <stdio.h>

void sort(int a[],int n){
	int i,j,swapped;
	for(i=0;i<n-1;i++){
		swapped=0;
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				swapped=1;
			}
		}
		if(!swapped) break;
	}
}

void merge(int a[], int n, int b[], int m, int c[], int N){
	int i;
	for(i=0;i<N;i++){
		if(i<n) c[i]=a[i];
		else c[i]=b[i-n];
	}
	sort(c,N);
}

void print(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

main(){
	int i,n,m,N;
	printf("Enter size of Array 1 : ");
	scanf(" %d", &n);
	printf("Enter size of Array 2 : ");
	scanf(" %d", &m);
	int a[n],b[m],c[N=n+m];
	printf("Array 1 :\n");
	for(i=0;i<n;i++)
		scanf(" %d", &a[i]);
	sort(a,n);
	print(a,n);
	printf("Array 2 :\n");
	for(i=0;i<m;i++)
		scanf(" %d", &b[i]);
	sort(b,m);
	print(b,m);
	printf("Merged Array :\n");
	merge(a,n,b,m,c,N);
	print(c,N);
}