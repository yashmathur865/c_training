#include<stdio.h>
#include<stdlib.h>

int FindMedian(int rows,int cols,int** arr){
    int min=arr[0][0];
    int max=arr[0][cols-1];
    for(int i=1;i<rows;i++){
        if(arr[i][0]<min) min=arr[i][0];
    }
    for(int i=1;i<rows;i++){
        if(arr[i][cols-1]>max) max=arr[i][cols-1];
    }

    while(min<max){
        int medPos=(rows*cols+1)/2;
        int mid = min + (max-min)/2;
        int midPos=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(arr[i][j]<=mid) midPos++;
            }
        }
        if(midPos<medPos){
            min=mid+1;
        }
        else{
            max=mid;
        }
    }
    return min;
}

int main(){
    int rows,cols,median;
    printf("Enter Rows and Columns of the matrix\n");
    scanf("%d %d",&rows,&cols);

    int **arr = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++){
        arr[i] = (int *)malloc(cols*sizeof(int));
    }

    printf("Enter The Array Elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    median=FindMedian(rows,cols,arr);
    printf("The median of the entered array is %d",median);
}