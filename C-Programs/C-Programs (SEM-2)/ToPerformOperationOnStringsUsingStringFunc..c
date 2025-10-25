#include <stdio.h>
#include <string.h>
main(){
	char s[50];
	char n[50]="Extra ";
	printf("Enter a String :\n");
	gets(s);
	printf("Added String : ");
	puts(strcat(n,s));
	printf("Copied String : ");
	puts(strcpy(n,s));
	printf("Reversed String : ");
	puts(strrev(s));
	printf("Length String : %d", strlen(s));
}