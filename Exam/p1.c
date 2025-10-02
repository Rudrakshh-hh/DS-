#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char name[50],authName[50];
    int price;
}book;

void main()
{
    int n;
    printf("Enter the number of Books: ");
    scanf("%d",&n);
    book *b;
    b=(book*)malloc(n*sizeof(book));
    if(b==NULL)
        printf("Cannot Allocate Memory\n");
    else
    {
        printf("Memory Allocated Successfully\n");
        for(int i=0;i<n;i++)
        {
            printf("Enter Details For Employee %d",i+1);
            
        }
    }
}