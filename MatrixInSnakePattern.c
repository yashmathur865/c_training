#include<stdio.h>
#include<stdlib.h>

void printSnakePattern(int** arr,int rows,int cols){
    for(int i=0;i<rows; i++) {
        if (i % 2==0) {
            for(int j = 0; j < cols; j++) {
                printf("%d ", arr[i][j]);
            }
        }else{
            for(int j=cols - 1; j >= 0;j--) {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int rows,cols;
    scanf("%d %d",&rows,&cols);

    int** arr=(int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        arr[i]=(int*)malloc(cols*sizeof(int));
    }

    printf("Enter Elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Array in snake pattern:\n");
    printSnakePattern(arr, rows, cols);

    for (int i=0;i<rows;i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}