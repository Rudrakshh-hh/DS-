// Palindrome List

#include<stdio.h>
#include<stdlib.h>
typedef struct singlyNode{
    int info;
    struct singlyNode* next;
}Node;

Node* insertEnd(Node* head,int item){
    Node* temp=(Node*)malloc(sizeof(Node));
    if(!temp){
        printf("Overflow");
        exit(0);
    }
    if(!head){
        temp->next=head;
        temp->info=item;
        return temp;
    }
    Node* t=head;
    while(t->next)
        t=t->next;
    temp->next=NULL;
    temp->info=item;
    t->next=temp;
    return head;
}
void display(Node* head){
    while(head){
        printf("%d ",head->info);
        head=head->next;
    }
    printf("\n");
}
Node* reverse(Node* head){
    Node* curr,*prev,*next;
    curr=head;
    prev=next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int isPalindrome(Node* head){
    if(head==NULL){
        printf("List empty\n");
        exit(0);
    }
    Node* fast,*slow;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // slow is middle part
    fast=reverse(slow->next);
    slow=head;
    while(fast!=NULL){
        if(fast->info!=slow->info)
            return 0;
        fast=fast->next;
        slow=slow->next;
    }
    return 1;
}

int main(){
    Node* head=NULL;
    head=insertEnd(head,1);
    head=insertEnd(head,1);
    head=insertEnd(head,2);
    head=insertEnd(head,1);
    head=insertEnd(head,1);
    display(head);
    if(isPalindrome)
        printf("List Is Palindrome\n");
    else
        printf("List Is not Palindrome\n");
    return 0;
}