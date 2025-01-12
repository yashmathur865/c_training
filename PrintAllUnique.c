//Print All Unique wth frequency more than 1
#include <stdio.h>
#include <string.h>


int findStringIndex(char arr[][51],int size,char *str){
    for(int i=0;i<size;i++){
        if(strcmp(arr[i],str)==0){
            return i;
        }
    }
    return -1;
}

int main(){
    int rows, cols;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d",&rows,&cols);

    char arr[rows][cols][51];

    printf("Enter the strings:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%s",arr[i][j]);
        }
    }

    char uniqueStrings[rows*cols][51];
    int counts[rows*cols];
    for(int i=0;i<rows*cols;i++){
        counts[i]=0;
    }
    int uniqueCount=0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int index=findStringIndex(uniqueStrings,uniqueCount,arr[i][j]);
            if(index==-1){
                strcpy(uniqueStrings[uniqueCount],arr[i][j]);
                counts[uniqueCount] = 1;
                uniqueCount++;
            } else {
                counts[index]++;
            }
        }
    }

    int foundDuplicates=0;
    for(int i=0;i<uniqueCount;i++){
        if(counts[i]>1){
            printf("%s - %d\n", uniqueStrings[i], counts[i]);
            foundDuplicates=1;
        }
    }

    if(!foundDuplicates){
        printf("No duplicates found\n");
    }
    return 0;
}
