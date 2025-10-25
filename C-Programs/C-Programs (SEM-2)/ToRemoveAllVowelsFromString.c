#include <stdio.h>
#include <ctype.h>
main(){
	char c,str[50],strnew[50];
	int i=0,k=0;
	printf("Enter a String :\n");
	gets(str);
	printf("Your String : ");
	puts(str);
	while(str[i]!='\0'){
		c=toupper(str[i]);
		if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		i++;
		else strnew[k++]=str[i++];
	}
	printf("After removing vowels : ");
	puts(strnew);
}
