// Write a C program to create a singly linked list and display it in reverse order using recursion.

#include<stdio.h>
#include<stdlib.h>
struct singlyNode{
    int info;
    struct singlyNode *next;
};
typedef struct singlyNode Node;

void insertFront(Node** head,int item){
    Node* temp=(Node*)malloc(sizeof(Node));
    if(!temp){
        printf("Overflow");
        return;
    }
    temp->next=*head;
    temp->info=item;
    *head=temp;
}

void displayList(Node* head){
    while(head){
        printf("%d ",head->info);
        head=head->next;
    }
}

void displayReverse(Node* head){
    if (head==NULL)
        return;
    displayReverse(head->next);
    printf("%d ",head->info);
}

int main(){
    Node* head=NULL;
    int ch,flag=1,item;
    while(flag){
        printf("1- Insert Element\n2- Exit\n\nEnter Your Choice- ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Element to be Inserted: ");
                scanf("%d",&item);
                insertFront(&head,item);
                break;
            case 2:
                flag=!flag;
                break;
            default:
                printf("Wrong Input...\n");
                return 0;
        }
    }
    printf("\nCurrent List - ");
    displayList(head);
    printf("\nReversed List - ");
    displayReverse(head);
    return 0;
}