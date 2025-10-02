#include<stdio.h>
#include<stdlib.h>
typedef struct singlyNode{
    int info;
    struct singlyNode* next;
}Node;

Node* insert(Node* head,int info){
    Node* temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL){
        printf("Overflow\n");
        exit(0);
    }
    temp->next=head;
    temp->info=info;
    head=temp;
    return head;
}
void display(Node* head){
    if(head==NULL){
        printf("List is Empty");
        exit(0);
    }
    while(head){
        printf("%d ",head->info);
        head=head->next;
    }
}
Node* isCycle(Node* head){
    Node* slow,*fast;
    slow=fast=head;
    if(slow==NULL){
        printf("List is Empty\n");
        exit(0);
    }
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main(){
    Node* head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);
    // display(head);
    head->next->next->next->next->next=head->next->next;
    Node* start=isCycle(head);
    if(start!=NULL){
        printf("Cycle Starts at the address with element %d\n",start->info);
    }
    return 0;
}