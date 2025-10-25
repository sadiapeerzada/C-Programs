#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insert(struct Node** head, int data, int index) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node* temp = *head;
    int size = 1;

    // Finding size of the circular linked list
    while (temp->next != *head) {
        temp = temp->next;
        size++;
    }

    // Normalize index to loop around
    index = index % size;  

    // Insert at head position
    if (index == 0) {
        struct Node* last = temp; // temp is already at last node
        last->next = newNode;
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Insert at given index
    temp = *head;
    int i;
    for (i=0; i<index-1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void del(struct Node** head, int index) {
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    int size = 1;

    // Count the number of nodes
    while (temp->next != *head) {
        temp = temp->next;
        size++;
    }

    // Adjust index to wrap around
    index = index % size;

    // If deleting the head node
    if (index == 0) {
    	
        // If only one node in the list
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL;
            return;
        }
        
		struct Node* last = *head;
		
        while (last->next != *head)  // Find the last node
            last = last->next;
        
        struct Node* delNode = *head;
        *head = (*head)->next;  // Move head to the next node
        last->next = *head;      // Update last node to point to new head
        free(delNode);
        return;
    }

    // Traverse to the node before the one to delete
    temp = *head;
    for (int i=0; i<index-1; i++)
        temp = temp->next;

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

void display(struct Node* head){
	if(head == NULL){
		printf("Empty!\n");
		return;
	}
	printf("HEAD->");
	struct Node* temp = head;
	do{
		printf("%d->", temp->data);
		temp = temp->next;
	}while(temp != head);
	printf("HEAD\n");
}

void main(){
	struct Node* head = NULL;
	int pos, data, choice;
	printf("List created, enter node : ");
	scanf("%d", &data);
	insert(&head, data, 0);
	while(1){
		printf("1. Insert\n2. Delete\n");
		printf("3. Display\n4. Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Position : ");
				scanf("%d", &pos);
				if(pos<1){
					printf("Enter a valid position!\n");
					break;
				}
				printf("Enter Node : ");
				scanf("%d", &data);
				insert(&head, data, pos-1);
				display(head);
				break;
			case 2:
				printf("Position : ");
				scanf("%d", &pos);
				if(pos<1){
					printf("Enter a valid position!\n");
					break;
				}
				del(&head, pos-1);
				printf("Deleted position %d\n", pos);
				display(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				exit(1);
			default:
				printf("Enter a valid choice!\n");
		}
	}
}