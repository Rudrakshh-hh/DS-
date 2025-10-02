// to rotate a list k times

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

Node* rotate(Node* head, int k){
    int count=0;
    Node* temp=head,*nHead,*nTail=head;
    while(temp->next!=NULL){
        ++count;
        temp=temp->next;
    }
    k=k%count;
    if(k==0)
        return head;
    for(int i=0;i<count-k;i++)
        nTail=nTail->next;
    nHead=nTail->next;

    nTail->next=NULL;
    temp->next=head;
    return nHead;
}

int main(){
    Node* head=NULL;
    head=insertEnd(head,1);
    head=insertEnd(head,2);
    head=insertEnd(head,3);
    head=insertEnd(head,4);
    head=insertEnd(head,5);
    display(head);
    int k;
    printf("Enter the value of k-");
    scanf("%d",&k);
    head=rotate(head,k);
    display(head);
}