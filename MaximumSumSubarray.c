#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isDigit(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    return -1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int FindLargestSumSubarray(int n,int arr[n]){
    int maxEnding=arr[0];
    int res=arr[0];
    for(int i=1;i<n;i++){
        maxEnding=max(maxEnding+arr[i],arr[i]);
        res=max(maxEnding,res);
    }
    return res;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int largestSumSubarray;
    char str[500];
    scanf("%[^\n]%*c",str);
    int arr[105];
    int i=1;
    int index=0;
    while(str[i]!=']'){

        if(str[i]==' '){
            i++;
            continue;
        }

        if(str[i]=='-'){
            i++;
            continue;
        }
        if(isDigit(str[i])==1){
            int sign=1;
            if(str[i-1]=='-'){
                sign=-1;
            }
            int num=0;
            while(isDigit(str[i])==1){
                num = num*10 + (str[i]-'0');
                i++;
            }
            num*=sign;
            arr[index]=num;
            index++;
        }
    }

    largestSumSubarray=FindLargestSumSubarray(index,arr);

    printf("%d",largestSumSubarray);

    return 0;
}