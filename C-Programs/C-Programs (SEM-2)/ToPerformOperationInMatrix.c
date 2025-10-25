#include <stdio.h>
void printarr(int n, int a[n][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
main(){
	int n=3,a[n][n],b[n][n],i,j;
	int s[n][n],d[n][n],p[n][n],t1[n][n],t2[n][n];
	printf("Enter 1st Matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf(" %d",&a[i][j]);
	printf("Enter 2nd Matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf(" %d",&b[i][j]);
			s[i][j]=a[i][j]+b[i][j];
			d[i][j]=a[i][j]-b[i][j];
			p[i][j]=a[i][j]*b[i][j];
			t1[j][i]=a[i][j];
			t2[j][i]=b[i][j];
		}
	printf("Summed Array :\n");
	printarr(n,s);
	printf("Difference Array :\n");
	printarr(n,d);
	printf("Product Array :\n");
	printarr(n,p);
	printf("Transposed Array 1:\n");
	printarr(n,t1);
	printf("Transposed Array 2:\n");
	printarr(n,t2);
	}