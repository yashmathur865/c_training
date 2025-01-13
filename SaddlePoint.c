#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns\n");
    scanf("%d %d",&rows,&cols);
    int arr[rows][cols];

    printf("Enter Elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int saddlePointFound = 0;

    for(int i=0;i<rows;i++){
        int minInRow=arr[i][0];
        int colIndex=0;

        for (int j=1;j<cols;j++){
            if (arr[i][j]<minInRow){
                minInRow=arr[i][j];
                colIndex=j;
            }
        }

        int isSaddlePoint=1;
        for(int k=0;k<rows;k++){
            if(arr[k][colIndex]>minInRow){
                isSaddlePoint=0;
                break;
            }
        }

        if(isSaddlePoint){
            printf("Saddle Point: %d\n",minInRow);
            saddlePointFound = 1;
        }
    }
    if(!saddlePointFound){
        printf("-1\n");
    }

    return 0;
}
