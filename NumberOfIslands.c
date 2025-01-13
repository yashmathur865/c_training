// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

#include<stdio.h>

void markIsland(int rows,int cols,char arr[rows][cols],int i,int j){
    if(i<0 || i>=rows || j<0 || j>=cols || arr[i][j]!='1'){
        return;
    }
    arr[i][j]='2';
    markIsland(rows,cols,arr,i+1,j);
    markIsland(rows,cols,arr,i,j+1);
    markIsland(rows,cols,arr,i-1,j);
    markIsland(rows,cols,arr,i,j-1);
}

int main(){
    printf("Enter the number of rows and columns\n");
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    char arr[rows][cols];
    printf("Enter Elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf(" %c",&arr[i][j]);
        }
    }

    int islandCount=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j]=='1'){
                markIsland(rows,cols,arr,i,j);
                islandCount++;
            }
        }
    }

    printf("The Number of islands are: %d\n",islandCount);

}