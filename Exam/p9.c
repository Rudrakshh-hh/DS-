// Write a program to find the element that appears more than ⌊n/2⌋ times in an array (if any). Use the Boyer-Moore Voting Algorithm.

#include<stdio.h>
int main(){
    int arr[]={2,2,1,1,1,2,2},n=sizeof(arr)/sizeof(arr[0]);
    
    int candid=arr[0],count=1;
    for(int i=1;i<n;i++){
        if(candid==arr[i])
            count++;
        else    
            count--;

        if(count==0){
            candid=arr[i];
            count=1;
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(candid==arr[i])
            count++;
    }
    if(count>n/2)
        printf("%d\n",candid);
    else
        printf("NO\n");
}
