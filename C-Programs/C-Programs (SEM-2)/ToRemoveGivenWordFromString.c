#include <stdio.h>
#include <string.h>
int del(char s[], char w[], char *ns){
	int i=0, count_tally=strlen(w);
	int start,end=-1;
	while(s[i]!='\0'){
		int counter=0,k=0;
		if(s[i]==w[k] && (i==0 || s[i-1]==' ')){
			start=i;
			for(;k<count_tally;k++,i++){
				if(s[i]==w[k]) counter++;
				else break;
			}
			if(counter==count_tally && (s[i]==' ' || s[i]=='\0')){
				end=i;
				break;
			}
		}
		else i++;
	}
	i=0;
	if(end!=-1){
		while(s[i]!='\0'){
			if(i>=start && i<=end){
				i++;
				continue;
			}
			*ns++=s[i++];
		}
		return start;
	}
	return 0;
}
main(){
	char str[101],strnew[101],word[50];
	printf("Enter the String (Max 100) :\n");
	gets(str);
	printf("Enter the word to delete : ");
	gets(word);
	int index=del(str, word, strnew);
	if(index){
		printf("Word deleted at index %d\n",index);
		puts(strnew);
	}
	else printf("Word not found!");
}