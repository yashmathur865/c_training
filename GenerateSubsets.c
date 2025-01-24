#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

void generateSubsets(int totalNumbers, int numArr[totalNumbers], int subset_array[totalNumbers], int index, int start, int *subset_number, int total_subset){
    if(index>0){
        printf("[");
        for(int i=0;i<index;i++){
            if(i>0)printf(", ");
            printf("%d",subset_array[i]);
        }
        if(*subset_number == total_subset){
            printf("]");
        }
        else{
            printf("], ");
        }

        (*subset_number)++;
    }

    for (int i=start;i<totalNumbers;i++){
        subset_array[index]=numArr[i];
        generateSubsets(totalNumbers,numArr,subset_array,index+1,i+1,subset_number,total_subset);
    }
}

int main() {
     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[500];
    scanf("%s",str);

    if(strcmp(str,"")==0){
        printf("[]\n");
        return 0;
    }

    int totalNumbers = 1;
    int index = 0;
    while (str[index] != '\0') {
        if (str[index] == ',') {
            totalNumbers++;
        }
        index++;
    }

    int numArr[totalNumbers];
    int numArrIndex = 0;
    index=0;

    while(str[index]!='\0'){
        if(isDigit(str[index])){
            int num=0;
            while(str[index]!='\0' && isDigit(str[index])){
                num=num*10+(str[index]-'0');
                index++;
            }
            numArr[numArrIndex++]=num;
        }
        else {
            index++;
        }
    }

    int total_subset = pow(2,totalNumbers);
    int subset_number = 2;

    int subset_array[totalNumbers];
    printf("[");
    printf("[], ");
    generateSubsets(totalNumbers,numArr,subset_array,0,0,&subset_number,total_subset);
    printf("]");
    return 0;
}