#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverseColumn(int low,int high,int rows,int cols,int arr[rows][cols]){
    for(int k=0;k<cols;k++){
        int i=low;
        int j=high;
        while(i<j){
            swap(&arr[i][k],&arr[j][k]);
            i++;
            j--;
        }
    }
}

void rotateByK(int rows,int cols,int arr[rows][cols],int k){
    k=k%rows;
    reverseColumn(0,k-1,rows,cols,arr);
    reverseColumn(k,rows-1,rows,cols,arr);
    reverseColumn(0,rows-1,rows,cols,arr);

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows;
    int cols;
    printf("Enter number of rows and columns\n");
    scanf("%d %d",&rows, &cols);

    int arr[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int k;
    printf("Enter the value of k\n");
    scanf("%d",&k);
    rotateByK(rows,cols,arr,k);
    return 0;
}

