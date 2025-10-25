#include <stdio.h>
#include <stdlib.h>

struct ArrayQueue{
	int queue[50];
	int front;
	int rear;
};

typedef struct QueueNode{
	int data;
	struct QueueNode* next;
}Node;

void push(struct ArrayQueue* queue, int data){
	if(queue->rear == 49){
		printf("Queue is Full!\n");
		return;
	}
	if(queue->rear == -1){
		queue->front = queue->rear = 0;
	}
	else queue->rear++;
	queue->queue[queue->rear] = data;
}

int pop(struct ArrayQueue* queue){
	
	int temp = queue->queue[queue->front++];
	
	if(queue->front > queue->rear){
		queue->front = queue->rear = -1;
	}
	return temp;
}

int peek(struct ArrayQueue* queue){
	return queue->queue[queue->front];
}

void display(struct ArrayQueue* queue){
	int front = queue->front;
	printf("Front -> ");
	while(front != queue->rear + 1)
		printf("%d -> ", queue->queue[front++]);
	printf("Rear\n");
}

void Lpush(Node** front, int data){
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(*front == NULL){
		*front = newNode;
		return;
	}
	Node* rear = *front;
	while(rear->next != NULL){
		rear = rear->next;
	}
	rear->next = newNode;
}

int Lpop(Node** front){
	Node* delNode = *front;
	int temp = delNode->data;
	*front = delNode->next;
	free(delNode);
	return temp;
}

int Lpeek(Node* front){
	return front->data;
}

void Ldisplay(Node* front){
	Node* temp = front;
	printf("Front -> ");
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("Rear\n");
}

void main(){
	int choice, data;
	printf("Implement using?\n1. Array\n2. List\n");
	scanf(" %d", &choice);
	if(choice == 1){
		printf("Limit : 50 elements!\n");
		
		struct ArrayQueue queue;
		queue.front = -1;
		queue.rear = -1;
		
		while(1){
			printf("0. Exit\n");
			printf("1. Push  2. Pop\n3. Peek  4. Display\n");
			scanf(" %d", &choice);
			switch(choice){
				case 0: exit(1);
				case 1:
					printf("Input data : ");
					scanf("%d", &data);
					push(&queue, data);
					//display(&queue);
					break;
				case 2:
					if(queue.rear == -1){
						printf("Queue is Empty!\n");
						break;
					}
					printf("Popped %d!\n", pop(&queue));
					//display(&queue);
					break;
				case 3:
					if(queue.rear == -1){
						printf("Queue is Empty!\n");
						break;
					}
					printf("Front is %d!\n", peek(&queue));
					//display(&queue);
					break;
				case 4:
					if(queue.rear == -1){
						printf("Queue is Empty!\n");
						break;
					}
					display(&queue);
					break;
				default:
					printf("Enter a valid choice!\n");
			}
		}
	}
	else{
		Node* front = NULL;
		while(1){
			printf("0. Exit\n");
			printf("1. Push  2. Pop\n3. Peek  4. Display\n");
			scanf(" %d", &choice);
			switch(choice){
				case 0: exit(1);
				case 1:
					printf("Input data : ");
					scanf("%d", &data);
					Lpush(&front, data);
					//Ldisplay(front);
					break;
				case 2:
					if(front == NULL){
						printf("Queue is Empty!\n");
						break;
					}
					printf("Popped %d!\n", Lpop(&front));
					//Ldisplay(front);
					break;
				case 3:
					if(front == NULL){
						printf("Queue is Empty!\n");
						break;
					}
					printf("Top is %d!\n", Lpeek(front));
					//Ldisplay(front);
					break;
				case 4:
					if(front == NULL){
						printf("Queue is Empty!\n");
						break;
					}
					Ldisplay(front);
					break;
				default:
					printf("Enter a valid choice!\n");
			}
		}
	}
}