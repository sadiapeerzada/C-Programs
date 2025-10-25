#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
int elements=0;
struct Node* createNode(int data){
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data=data;
	newNode->next=NULL;
	
	return newNode;
}

void insertAtFirst(struct Node** head, int data){
	
	struct Node* newNode = createNode(data);
	
	newNode->next = *head;
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
		free(temp);
		*head = NULL;
		elements--;
		return;
	}
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
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
	for (i=0; i<position-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL){
        printf("Position out of range\n");
        return;
	}
	struct Node* next = temp->next->next;
	free(temp->next);
	temp->next = next;
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

int main(){
	
	struct Node* head = NULL;
	
	int data,position;
	printf("Creating Linked List...\nEnter first Node : ");
	scanf("%d", &data);
	insertAtFirst(&head, data);
	printf("Linked List Created!\n");
	display(head);
	
	while(1){
		int choice;
		printf("0. Exit\n");
		printf("1. Insert at beginning\n2. Insert at end\n");
		printf("3. Insert at middle\n4. Insert at position\n");
		printf("5. Delete at beginning\n6. Delete at end\n");
		printf("7. Delete at middle\n8. Delete at position\n");
		scanf("%d", &choice);
		switch(choice){
			//case 9:printf("Length : %d\n", elements);break; //for debugs
			case 0:
				//printf("Length : %d", elements);//for debugs
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
			default:
				printf("Enter a valid choice!\n");
		}
	}
	return 0;
}