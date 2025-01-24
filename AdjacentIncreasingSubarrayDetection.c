#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isDigit(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    return 0;
}

int isIncreasing(int size,int arr[size],int helper[size],int k){
    if(size<2*k) return 0;
    if(k==1) return 1;
    for(int i=0;i<=2*k;i++){
        if(helper[i]>=k && helper[i+k]>=k){
            return 1;
        }
    }
    return 0;
}

void maxAdjacentIncreasing(int size,int arr[size]){
    int helper[size];
    helper[size-1]=1;
    for(int i=size-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            helper[i]=helper[i+1]+1;
        }
        else{
            helper[i]=1;
        }
    }

    int low=1,high=size/2;
    int res=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(isIncreasing(size,arr,helper,mid)){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    printf("%d",res);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[1000];
    scanf("%[^\n]%*c",&str);
    int i=0;
    int size=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            size++;
            i++;
            continue;
        }
        i++;
    }
    size=size+1;
    int arr[size];
    int index=0;
    i=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            i++;
            continue;
        }
        if(isDigit(str[i])==1){
            int num=0;
            while(isDigit(str[i])==1){
                num=num*10 + str[i]-'0';
                i++;
            }
            arr[index++]=num;
        }
        i++;
    }
    maxAdjacentIncreasing(size,arr);
    return 0;
}
