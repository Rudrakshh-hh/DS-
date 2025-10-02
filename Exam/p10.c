// 8. Product of Array Except Self (without division)

#include<stdio.h>

void productExceptSelf(int arr[], int n, int result[]) {
    int prefix = 1;

    // Step 1: prefix product
    for(int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= arr[i];
    }

    // Step 2: suffix product
    int suffix = 1;
    for(int i = n-1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= arr[i];
    }
}

int main(){
    int arr[]={1,2,3,4},prod=1,result[4];
    int n=sizeof(arr)/sizeof(arr[0]);
    
    productExceptSelf(arr, n, result);

    printf("\nUpdated Array-\n");
    for(int i=0;i<n;i++)
        printf("%d ",result[i]);
}