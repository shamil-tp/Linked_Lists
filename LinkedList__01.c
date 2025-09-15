#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int data){
	struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
}

void insert(int data){
	struct Node* newNode = create(data);
	if(head == NULL){
		head = newNode;
	}else{
		struct Node* current = head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
}

void delete(){
	struct Node* current = head;
	while(current->next->next != NULL){
		current = current->next;
	}
	struct Node* temp = current;
	temp = temp->next;
	current->next = NULL;
	free(temp);
}

void display(){
	struct Node* current = head;
	while(current->next != NULL){
		printf("%d -> ",current->data);
		current = current->next;
	}
	printf("%d -> NULL\n",current->data);
}

int main(){
	int choice,value;
	while(1){
		printf("\n|___Linked List___|\n1. Insert\n2. Delete\n3. Display\n4. Exit");
		printf("\nEnter Choice: ");
		scanf("%d",&value);
		
		switch(value){
			case 1:
				{
					printf("\nEnter Value to INSERT: ");
					scanf("%d",&value);
					insert(value);
					break;
				}
			case 2:
				{
					printf("\nEnter Value to DELETE: ");
					//scanf("%d",&value);
					delete();
					break;
				}
			case 3:
				{
					printf("\n_DISPLAY elements_\n");
					display();
					break;
				}
			case 4:
				{
					printf("\nExiting!...\n");
					exit(0);
					break;
				}
			default:
				{
					printf("\nInvalid Choice! Try Again\n");
				}
		}
	}

}
