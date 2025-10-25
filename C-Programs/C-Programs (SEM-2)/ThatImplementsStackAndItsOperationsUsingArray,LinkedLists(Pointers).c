#include <stdio.h>
#include <stdlib.h>

struct ArrayStack{
	int stack[50];
	int top;
};

typedef struct StackNode{
	int data;
	struct StackNode* next;
}Node;

void push(struct ArrayStack* stack, int data){
	if(stack->top == 50){
		printf("Stack is Full!\n");
		return;
	}
	(stack->top)++;
	stack->stack[stack->top] = data;
}

int pop(struct ArrayStack* stack){
	int temp = stack->stack[stack->top];
	(stack->top)--;
	return temp;
}

int peek(struct ArrayStack* stack){
	return stack->stack[stack->top];
}

void display(struct ArrayStack* stack){
	int top = stack->top;
	printf("Top -> ");
	while(top != -1)
		printf("%d -> ", stack->stack[top--]);
	printf("Bottom\n");
}

void Lpush(Node** top, int data){
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

int Lpop(Node** top){
	Node* delNode = *top;
	int temp = delNode->data;
	*top = delNode->next;
	free(delNode);
	return temp;
}

int Lpeek(Node** top){
	return (*top)->data;
}

void Ldisplay(Node* top){
	Node* temp = top;
	printf("Top -> ");
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("Bottom\n");
}

void main(){
	int choice, data;
	printf("Implement using?\n1. Array\n2. List\n");
	scanf(" %d", &choice);
	if(choice == 1){
		printf("Limit : 50 elements!\n");
		
		struct ArrayStack stack;
		stack.top = -1;
		
		while(1){
			printf("0. Exit\n");
			printf("1. Push  2. Pop\n3. Peek  4. Display\n");
			scanf(" %d", &choice);
			switch(choice){
				case 0: exit(1);
				case 1:
					printf("Input data : ");
					scanf("%d", &data);
					push(&stack, data);
					//display(&stack);
					break;
				case 2:
					if(stack.top == -1){
						printf("Stack is Empty!\n");
						break;
					}
					printf("Popped %d!\n", pop(&stack));
					//display(&stack);
					break;
				case 3:
					if(stack.top == -1){
						printf("Stack is Empty!\n");
						break;
					}
					printf("Top is %d!\n", peek(&stack));
					//display(&stack);
					break;
				case 4:
					if(stack.top == -1){
						printf("Stack is Empty!\n");
						break;
					}
					display(&stack);
					break;
				default:
					printf("Enter a valid choice!\n");
			}
		}
	}
	else{
		Node* top = NULL;
		while(1){
			printf("0. Exit\n");
			printf("1. Push  2. Pop\n3. Peek  4. Display\n");
			scanf(" %d", &choice);
			switch(choice){
				case 0: exit(1);
				case 1:
					printf("Input data : ");
					scanf("%d", &data);
					Lpush(&top, data);
					//Ldisplay(top);
					break;
				case 2:
					if(top == NULL){
						printf("Stack is Empty!\n");
						break;
					}
					printf("Popped %d!\n", Lpop(&top));
					//Ldisplay(top);
					break;
				case 3:
					if(top == NULL){
						printf("Stack is Empty!\n");
						break;
					}
					printf("Top is %d!\n", Lpeek(&top));
					//Ldisplay(top);
					break;
				case 4:
					if(top == NULL){
						printf("Stack is Empty!\n");
						break;
					}
					Ldisplay(top);
					break;
				default:
					printf("Enter a valid choice!\n");
			}
		}
	}
}