#include<stdio.h>
#include<string.h>

void swap(char *str1, char *str2) {
    char temp[51];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}


void printInOrder(int rows,int cols,char arr[rows][cols][51]){
    char sorted[rows*cols][51];
    int index=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            strcpy(sorted[index++],arr[i][j]);
        }
    }
    int size=index;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(strcmp(sorted[j],sorted[j+1])>0){
                swap(sorted[j],sorted[j+1]);
            }
        }
    }

    printf("Sorted strings:\n");
    for(int i=0;i<size;i++){
        printf("%s\n",sorted[i]);
    }
}

int main(){
    printf("Enter the number of rows\n");
    int rows;
    scanf("%d",&rows);
    printf("Enter the number of columns\n");
    int cols;
    scanf("%d",&cols);
    char arr[rows][cols][51];

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%s",arr[i][j]);
        }
    }

    printInOrder(rows,cols,arr);
}