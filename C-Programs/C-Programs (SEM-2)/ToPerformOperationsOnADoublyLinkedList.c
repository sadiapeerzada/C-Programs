#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
int elements=0;
struct Node* createNode(int data){
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	
	return newNode;
}

void insertAtFirst(struct Node** head, int data){
	
	struct Node* newNode = createNode(data);
	
	if(*head == NULL){
		*head = newNode;
		elements++;
		return;
	}
	
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
	elements++;
}

void insertAtEnd(struct Node** head, int data){
	
	struct Node* newNode = createNode(data);
	
	if(*head == NULL){
		*head = newNode;
		elements++;
		return;
	}
	
	struct Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	elements++;
}

void insertAtPosition(struct Node** head, int data, int position){
	
	if(position==0){
		insertAtFirst(head, data);
		return;
	}
	
	struct Node* newNode = createNode(data);
	
	struct Node* temp = *head;
	int i;
	for(i=0; i<position-1 && temp != NULL ;i++){
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("Not in range, please enter valid position!\n");
		free(newNode);
		return;
	}
	
	newNode->next = temp->next;
	newNode->prev = temp;
	if(temp->next != NULL){
		temp->next->prev = newNode;
	}
	temp->next = newNode;
	elements++;
}

void deleteAtFirst(struct Node** head){
	
	if(*head == NULL){
		printf("Already empty!\n");
		return;
	}
	
	struct Node* temp = *head;
	*head = temp->next;
	if(*head != NULL){
		(*head)->prev = NULL;
	}
	free(temp);
	elements--;
}

void deleteAtEnd(struct Node** head){
	
	if(*head == NULL){
		printf("Already empty!\n");
		return;
	}
	
	struct Node* temp = *head;
	if(temp->next == NULL){
		*head = NULL;
		free(temp);
		elements--;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
	elements--;
}

void deleteAtPosition(struct Node** head, int position){
	
	if(*head == NULL){
		printf("Already empty!\n");
		return;
	}
	
	struct Node* temp = *head;
	if(position == 0){
		deleteAtFirst(head);
		return;
	}
	
	int i;
	for (i=0; i<position && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Position out of range\n");
        return;
	}
	if(temp->next != NULL){
		temp->next->prev = temp->prev;
	}
	if(temp->prev != NULL){
		temp->prev->next = temp->next;
	}
	free(temp);
	elements--;
}

void display(struct Node* head){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void displayReverse(struct Node* head){
	struct Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
}

int main(){
	
	struct Node* head = NULL;
	
	int data,position;
	printf("Creating Linked List...\nEnter first Node : ");
	scanf("%d", &data);
	insertAtFirst(&head, data);
	printf("Doubly Linked List Created!\n");
	display(head);
	
	while(1){
		int choice;
		printf("0. Exit\n");
		printf("1. Insert at beginning\n2. Insert at end\n");
		printf("3. Insert at middle\n4. Insert at position\n");
		printf("5. Delete at beginning\n6. Delete at end\n");
		printf("7. Delete at middle\n8. Delete at position\n");
		printf("9. Display\n10. Display in reverse\n");
		scanf("%d", &choice);
		switch(choice){
			case 11:printf("Length : %d\n", elements);break; //for debugs
			case 0:
				printf("Length : %d", elements);//for debugs
				exit(0);
			case 1:
				printf("Enter the node : ");
				scanf("%d", &data);
				insertAtFirst(&head, data);
				display(head);
				break;
			case 2:
				printf("Enter the node : ");
				scanf("%d", &data);
				insertAtEnd(&head, data);
				display(head);
				break;
			case 3:
				printf("Enter the node : ");
				scanf("%d", &data);
				insertAtPosition(&head, data, elements/2);
				display(head);
				break;
			case 4:
				printf("Enter the position : ");
				scanf("%d", &position);
				if(position<1){
					printf("Enter a valid position!\n");
					break;
				}
				printf("Enter the node : ");
				scanf("%d", &data);
				insertAtPosition(&head, data, position-1);
				display(head);
				break;
			case 5:
				printf("Deleting the first node...\n");
				deleteAtFirst(&head);
				display(head);
				break;
			case 6:
				printf("Deleting the last node...\n");
				deleteAtEnd(&head);
				display(head);
				break;
			case 7:
				printf("Deleting the middle node...\n");
				if(elements%2==1) deleteAtPosition(&head, elements/2);
				else deleteAtPosition(&head, elements/2-1);
				display(head);
				break;
			case 8:
				printf("Enter the position : ");
				scanf("%d", &position);
				if(position<1){
					printf("Enter a valid position!\n");
					break;
				}
				printf("Deleting node %d...\n", position-1);
				deleteAtPosition(&head, position);
				display(head);
				break;
			case 9:
				printf("Current List : ");
				display(head);
				break;
			case 10:
				printf("Reversed List : ");
				displayReverse(head);
			default:
				printf("Enter a valid choice!\n");
		}
	}
	return 0;
}