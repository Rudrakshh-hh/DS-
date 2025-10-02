// Find Pair with Given Sum k(Two-Pointer / Hashing)

#include<stdio.h>

// void findPair(int* arr,int n,int k){
//     int sum=0,flag=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             sum=arr[i]+arr[j];
//             if(sum==k){
//                 flag=1;
//                 printf("(%d,%d)",arr[i],arr[j]);
//             }
//             sum=0;
//         }
//     }
//     if(!flag)
//     printf("No Such Pair");
// }

// int main(){
//     int arr[]={8, 7, 2, 5, 3, 1};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k;
//     printf("Enter the value of k- ");
//     scanf("%d",&k);
//     findPair(arr,n,k);
//     return 0;
// }


// ORRRRR

void findPairs(int* arr,int n,int k){
    for(int i=0;i<n-1;i++){    //Sorting Array
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int start=0,end=n-1,flag=0;
    int sum;
    while(start<end){
        sum=arr[start]+arr[end];
        if(sum==k){
            printf("(%d, %d)",arr[start],arr[end]);
            start++;
            end--;
            flag=1;
        }
        else if(sum>k){
            end--;
        }
        else{
            start++;
        }
    }
    if(!flag){
        printf("No such pairs..\n");
    }
}
int main(){
    int arr[]={8, 7, 2, 5, 3, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    printf("Enter the value of k- ");
    scanf("%d",&k);
    findPairs(arr,n,k);
    return 0;
}