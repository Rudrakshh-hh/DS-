// Program to Find missing number in a 1 to n+1 array.

#include<stdio.h>
int missing(int *arr,int n){
    int total=0,sum=0;
    for(int i=1;i<=n+1;i++)
        total+=i;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return total-sum;
}

int main(){
    int arr[]={1,2,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Missing Number is- %d",missing(arr,n));
    return 0;
}