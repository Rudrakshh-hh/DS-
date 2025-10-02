// Rotate array to the right by k steps, where k is non-negative.

#include<stdio.h>
#include<stdlib.h>

void rotatePart(int *arr,int start,int end){
    start-=1;
    end-=1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void rotateRight(int *arr,int n,int k){
    rotatePart(arr,1,n);
    rotatePart(arr,1,k);
    rotatePart(arr,k+1,n);
}

int main(){
    int *arr,n,k;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    if(!arr){
        printf("Memory Not Allocated");
        return 0;
    }
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the number of times you want to rotate the array: ");
    scanf("%d",&k);
    k=k%n;
    printf("Array Before Rotation:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    rotateRight(arr,n,k);

    printf("\nArray after rotation:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}