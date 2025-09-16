//@gemini-cli summary
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insert(int data){
    struct Node* newNode =create(data);
    if(head == NULL){
        // newNode->next = head;
        head = newNode;
        printf("\n%d == %d",newNode->data,head->data);
    }else{
        struct Node* current = head;
        while(current->next != NULL ){
            current = current->next;

        }
        current->next = newNode;
    }

}

void deleteBeginning(){
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd(){
    struct Node* current = head;
    while(current->next->next != NULL){
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = NULL;
    free(temp);
}

int count(){
    struct Node* current = head;
    int count = 0;
    while(current->next != NULL){
        count++;
        current = current->next;
    }
    return count + 1;
}

void deletePosition(int position){
    if(position == 1){
        deleteBeginning();
        return;
    }
    if(count() == position){
        deleteEnd();
        return;
    }
    int count = 0;
    struct Node* current = head;
    while(current->next != NULL){
        count++;
        if(count + 1 == position){
            break;
        }
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void deleteValue(int value){
    struct Node* current = head;
    if(current->data == value){
        deleteBeginning();
        return;
    }
    while(current->next->data != value){
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return;
}

void display(){
    struct Node* current = head;
    printf("%d -> \n",head->data);
    while(current->next != NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("%d -> NULL",current->data);
    return;
}

int main(){
    int choice,value;
    while(1){
        printf("\n___Linked List___\n");
        printf("1.  Insert\n");
        printf("2.  Delete [BEGINNIG]\n");
        printf("3.  Delete [END]\n");
        printf("4.  Delete [POSITION]\n");
        printf("5.  Delete [DATA]\n");
        printf("6.  Display\n");
        printf("0.  Exit\n");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                {
                    printf("\nINSERT value: ");
                    scanf("%d",&value);
                    insert(value);
                    break;
                }
            case 2:
                {
                    printf("\nDELETE [BEGINNING]: ");
                    deleteBeginning();
                    break;
                }
            case 3:
                {
                    printf("\nDELETE [END]: ");
                    deleteEnd();
                    break;
                }
            case 4:
                {
                    printf("\nDELETE [POSITION]: ");
                    scanf("%d",&value);
                    deletePosition(value);

                    break;
                }
            case 5:
                {
                    printf("\nDELETE [DATA]: ");
                    scanf("%d",&value);
                    deleteValue(value);
                    break;
                }
            case 6:
                {
                    printf("\nDISPLAY ELEMENTS:\n");
                    display();
                    printf("\n count is = %d ",count());
                    break;
                }
            case 0:
                {
                    printf("\nEXITING!....");
                    exit(0);
                    break;
                }
            default:
                {
                    printf("\ninvalid choice!  Try again");
                    break;
                }
        }
    }

    return 0;
}