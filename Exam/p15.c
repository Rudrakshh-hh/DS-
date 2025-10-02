// Delete nth node from end

#include<stdio.h>
#include<stdlib.h>
typedef struct singlyNode{
    int info;
    struct singlyNode* next;
}Node;
Node* insert(Node* head, int item){
    Node* temp=(Node*)malloc(sizeof(Node));
    if(!temp){
        printf("Overflow\n");
        exit(0);
    }
    temp->next=head;
    temp->info=item;
    return temp;
}
void display(Node* head){
    while(head){
        printf("%d ",head->info);
        head=head->next;
    }
    printf("\n");
}

Node* deleteNthEnd(Node* head,int n){
    Node* fast,*slow,dummy;
    dummy.next=head;
    fast=slow=&dummy;

    for(int i=1;i<=n+1;i++)
        fast=fast->next;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* temp=slow->next;
    slow->next=slow->next->next;
    free(temp);
    return dummy.next;
}

int main(){
    int n;
    Node* head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);
    display(head);
    
    printf("Delete which node from end- ");
    scanf("%d",&n);
    head=deleteNthEnd(head,n);
    display(head);
}