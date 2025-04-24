// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include<stdio.h>

int main(){
    printf("Enter the number of rows and columns\n");
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    int arr[rows][cols];
    printf("Enter Elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int markrow[rows];
    for(int i=0;i<rows;i++){
    markrow[i] = 0;
    }
    int markcol[cols];
    for(int i=0;i<cols;i++){
    markcol[i] = 0;
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j]==0){
                markrow[i]=1;
                markcol[j]=1;
            }
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(markrow[i]==1 || markcol[j]==1){
                arr[i][j]=0;
            }
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
return 0;
}