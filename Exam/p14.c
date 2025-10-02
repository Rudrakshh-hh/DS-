// Program to Merge two sorted Lists

#include<stdio.h>
#include<stdlib.h>
typedef struct singlyNode{
    int info;
    struct singlyNode* next;
}Node;
Node* insert(Node* head, int item){
    Node* temp=(Node*)malloc(sizeof(Node*));
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
Node* mergedList(Node* head1,Node* head2){
    if(!head1)return head2;
    if(!head2)return head1;

    Node* merged=NULL;

    if(head1->info < head2->info){
        merged=head1;
        merged->next=mergedList(head1->next,head2);
    }
    else{
        merged=head2;
        merged->next=mergedList(head1,head2->next);
    }
    return merged;
}

int main(){
    Node* head1=NULL,*head2=NULL;

    // list 1
    head1=insert(head1,5);
    head1=insert(head1,3);
    head1=insert(head1,1);
    printf("List 1-\n");
    display(head1);
    // list 2
    head2=insert(head2,6);
    head2=insert(head2,4);
    head2=insert(head2,2);
    printf("List 2-\n");
    display(head2);

    printf("Merged List-\n");
    display(mergedList(head1,head2));
    return 0;
}