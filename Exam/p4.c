// Write a C program to create a singly linked list and calculate its length.

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
int calLength(node* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
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
    printf("\nLength of the List - %d",calLength(head));
    return 0;
}