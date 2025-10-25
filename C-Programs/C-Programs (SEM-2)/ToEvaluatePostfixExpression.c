#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

char pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    char popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

char peek(struct Node* top) {
    return (top) ? top->data : 0;
}

int evaluate(char* p){
	
	struct Node* top = NULL;
	
	while(*p != '\0'){
		if(*p == ',' || isspace(*p)){
			p++;
			continue;
		}
		if(isdigit(*p)){
			int num=0;
			while(*p != ','){
				num = num*10 + *(p++) - '0';
			}
			push(&top, num);
		}
		else{
			char op = *(p++);
			int a = pop(&top);
			int b = pop(&top);
			switch(op){
				case '+':
					push(&top, b+a);
					break;
				case '-':
					push(&top, b-a);
					break;
				case '*':
					push(&top, b*a);
					break;
				case '/':
					push(&top, b/a);
					break;
				case '^':
					push(&top, pow(b,a));
					break;
			}
		}
	} return pop(&top);
}
void main(){
	char postfix[101];

    printf("Enter a valid postfix expression:\n");
    gets(postfix);  // Ensure expression is already balanced with correct parentheses

    printf("Value: %d\n", evaluate(postfix));
}

/*
Test Expressions:
	45, 2, 2, *, 1, +, 2, ^, –, 4, 2, –, 5, *, /	Answer = 2
	2, 5, ^, 3, 2, 3, ^, *, –, 18, 3, /, +			Answer = 14
	40, 30, +, 10, 5, *, 25, /, +, 2, /				Answer = 36
*/