#include<stdio.h>
#include<string.h>

int main(){
    int rows, cols;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d", &rows, &cols);
    if(rows==0 || cols==0){
        printf("Enter Valid Rows and Columns\n");
        return 0;
    }

    char arr[rows][cols][51];
    printf("Enter the strings:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j <cols;j++){
            scanf("%s", arr[i][j]);
        }
    }

    int maxLength=0;
    int corX,corY;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(strlen(arr[i][j])>maxLength){
                maxLength=strlen(arr[i][j]);
                corX=i;
                corY=j;
            }
        }
    }

    printf("The Longest word entered is %s with length %d",arr[corX][corY],maxLength);

    return 0;
}