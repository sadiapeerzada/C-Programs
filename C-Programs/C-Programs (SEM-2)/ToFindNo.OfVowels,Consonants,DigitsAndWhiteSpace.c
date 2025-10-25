#include <stdio.h>
#include <ctype.h>
main(){
	int i=0,v=0,co=0,d=0,w=0;
	char s[50];
	printf("Enter the string :\n");
	gets(s);
	while(s[i]!='\0'){
		if(isalpha(s[i])){
			char c=tolower(s[i]);
			if(c=='a' || c=='e' || c=='i' ||c=='o' || c=='u')
			v++;
			else co++;
		}
		else if (isdigit(s[i])) d++;
		else if (s[i]==' ') w++;
		i++;
	}
	printf("Vowels=%d\nConsonants=%d\nDigits=%d\n",v,co,d);
	printf("White space=%d",w);
}