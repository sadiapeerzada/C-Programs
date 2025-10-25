#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

void push(struct Node** top, char x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

char pop(struct Node** top) {
    if (*top == NULL) return '\0';
    struct Node* temp = *top;
    char popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

char peek(struct Node* top) {
    return (top) ? top->data : '\0';
}

// Function to define precedence of operators
int rank(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    struct Node* top = NULL;
    push(&top, '(');  // Push an opening bracket
    strcat(infix, ")");  // Append closing bracket to match
    
    char *i = infix, *p = postfix;

    while (*i != '\0') {
        if (isalnum(*i)) {
            *(p++) = *(i++);
            *(p++) = ',';
        }
        else if (*i == '(') {
            push(&top, *i++);
        }
        else if (*i == ')') {
            while (peek(top) != '(') {
                *(p++) = pop(&top);
                *(p++) = ',';
            }
            pop(&top);  // Remove '('
            i++;
        }
        else {
            while (rank(*i) <= rank(peek(top)) && peek(top) != '(') {
                *(p++) = pop(&top);
                *(p++) = ',';
            }
            push(&top, *i++);
        }
    }

    *p = '\0';
}

int main() {
    char infix[101], postfix[101];

    printf("Enter a valid infix expression:\n");
    gets(infix);  // Ensure expression is already balanced with correct parentheses
    
    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);
    return 0;
}

/*
Test Expressions:
	(A+B)*(C+B)*(E/F)    Question 4
	
	4+2^(3+8/4)*3
	((A+B)–C*(D/E))+F
	
	((a/b)+c)-(d+(e*f))
	A+(B*C)/(D-E)
	5+(10/(2+3)*4
*/