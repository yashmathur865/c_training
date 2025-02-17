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

void merge(int n,int arr[n],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];
}

void mergeSort(int n,int arr[n],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(n,arr,l,m);
        mergeSort(n,arr,m+1,r);
        merge(n,arr,l,m,r);
    }
}

int main(){
     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[1000];
    scanf("%[^\n]%*c",str);
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
        int sign=1;
        if(str[i]=='-'){
            sign=-1;
            i++;
        }
        if(isDigit(str[i])){
            int num=0;
            while(isDigit(str[i])){
                num = num*10+(str[i]-'0');
                i++;
            }
            arr[index++]=num*sign;
        }
        else{
            i++;
        }
    }

    mergeSort(size,arr,0,size-1);

    int minDiff=__INT_MAX__;
    for(int i=1;i<size;i++){
        if(abs(arr[i]-arr[i-1])<minDiff){
            minDiff=abs(arr[i-1]-arr[i]);
        }
    }
    int count = 0;
    for(int i=1;i<size;i++){
        if(abs(arr[i]-arr[i-1])==minDiff){
            if(count>0){
                printf(",");
            }
            printf("[%d,%d]",arr[i-1],arr[i]);
            count++;
        }
    }

    return 0;
}