#include<stdio.h>
#include<stdlib.h>

int* SearchK(int rows,int cols,int** arr,int k){
    int i=0,j=cols-1;
    static int a=-1;
    int *ptr=&a;
    int *res =(int *)malloc(2*sizeof(int));
    while(i<rows && j>=0){
        if(arr[i][j]==k){
            res[0]=i;
            res[1]=j;
            return res;
        }
        else if(arr[i][j]>k){
            j--;
        }
        else{
            i++;
        }
    }
    return ptr;
}

int main(){
    int rows,cols;
    printf("Enter Rows and Columns of the matrix\n");
    scanf("%d %d",&rows,&cols);

    int **arr = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++){
        arr[i] = (int *)malloc(cols*sizeof(int));
    }

    int k;
    int *res;
    printf("Enter The Array Elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter The Value To Be Searched\n");
    scanf("%d",&k);

    res=SearchK(rows,cols,arr,k);
    if(*res==-1){
        printf("Element Not Found");
    }
    else{
        printf("Element is found at location arr[%d][%d]",res[0],res[1]);
    }
    return 0;
}