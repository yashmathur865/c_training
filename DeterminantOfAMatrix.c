#include<stdio.h>

int FindDeterminant(int n,int arr[n][n]){
    if(n==1){
        return arr[0][0];
    }
    int res=0;
    for(int i=0;i<n;i++){
        int temp = arr[0][i];
        if(i%2!=0){
            temp *= -1;
        }

        int tempMat[n-1][n-1];
        for(int j=1;j<n;j++){
            for(int k=0;k<n;k++){
                if(k!=i){
                    if(k<i) tempMat[j-1][k]=arr[j][k];
                    if(k>i) tempMat[j-1][k-1]=arr[j][k];
                }
            }
        }

        res=res+temp*FindDeterminant(n-1,tempMat);
    }
    return res;
}

int main(){
    int n,median,determinant;
    printf("Enter Rows and Columns of the matrix\n");
    scanf("%d",&n);

    int arr[n][n];

    printf("Enter The Array Elements\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    determinant=FindDeterminant(n,arr);
    printf("The Determinant Of the matrix is %d",determinant);
}