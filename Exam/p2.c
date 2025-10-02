// Reverse a Linked List 

#include<stdio.h>
#include<stdlib.h>
struct singlyNode{
    int info;
    struct singlyNode *next;
};
typedef struct singlyNode node;

void insertFront(node** head,int item){
    node* temp=(node*)malloc(sizeof(node));
    if(!temp){
        printf("Overflow");
        return;
    }
    temp->next=*head;
    temp->info=item;
    *head=temp;
}

void displayList(node* head){
    while(head){
        printf("%d ",head->info);
        head=head->next;
    }
}

void reverseList(node** head){
    node* curr=*head,*prev=NULL;
    while(curr){
        node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    *head=prev;
}

int main(){
    node* head=NULL;
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
    reverseList(&head);
    printf("\nReversed List- ");
    displayList(head);
    printf("\n");
}