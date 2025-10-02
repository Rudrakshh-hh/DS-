// Maximum Subarray Sum (Kadane’s Algorithm) 

#include<stdio.h>
int sArrSum(int* arr,int n){
    int curr=arr[0],max=arr[0];
    for(int i=1;i<n;i++){
        if(curr<0)
            curr=arr[i];
        else
            curr+=arr[i];
        
        if(curr>max)
            max=curr;
    }
    return max; 
}

int main(){
    int arr[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Subarray Sum- %d",sArrSum(arr,n));
    return 0;
}