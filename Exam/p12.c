//  Spiral Order Traversal of a 2D Array (Matrix)

#include<stdio.h>

void spiralOrder(int m,int n,int arr[m][n]){
    int top=0,bottom=m-1,left=0,right=n-1;
    printf("Spiral Order-\n( ");
    while(top<=bottom && left<=right){
        // Top Row traversal L->R
        for(int i=left;i<=right;i++)
            printf("%d ",arr[top][i]);
        top++;

        // Right Column traversal T->B
        for(int i=top;i<=bottom;i++)
            printf("%d ",arr[i][right]);
        right--;

        // Bottom Row traversal if present
        if(top<=bottom){
            for(int i=right;i>=left;i--)
                printf("%d ",arr[bottom][i]);
            bottom--;
        }

        // Left Row traversal if present
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                printf("%d ",arr[i][left]);
            left++;
        }
    }
    printf(")\n");
}

int main(){
    int n,m;
    printf("Enter the rows of the Matrix-");
    scanf("%d",&m);
    printf("Enter the columns of the Matrix-");
    scanf("%d",&n);
    int arr[m][n];
    printf("Enter the Elements of the Matrix-\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("Matrix is-\n\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    spiralOrder(m,n,arr);
    return 0;
}