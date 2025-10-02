// Remove Duplicate Nodes

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
Node* removeDuplicate(Node* head){
    Node* curr=head;

    while(curr!=NULL){
        Node* run=curr;
        while(run->next!=NULL){
            if(run->next->info==curr->info){
                Node* temp=run->next;
                run->next=run->next->next;
                free(temp);
            }
            else
                run=run->next;
        }
        curr=curr->next;
    }
}


int main(){
    Node* head=NULL;
    head=insertEnd(head,1);
    head=insertEnd(head,2);
    head=insertEnd(head,1);
    head=insertEnd(head,4);
    head=insertEnd(head,5);
    display(head);
    
    printf("\nRemoved Duplicate Nodes\n");
    head=removeDuplicate(head);
    display(head);
}