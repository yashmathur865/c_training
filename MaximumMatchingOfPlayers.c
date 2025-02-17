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

int calcMaximumMatching(int n1,int n2,int arr1[n1],int arr2[n2]){
    int count=0;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            count++;
            i++;
            j++;
        }
    }
    return count;
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

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str1[1000];
    char str2[1000];
    scanf("%[^\n]%*c",str1);
    scanf("%[^\n]%*c",str2);
    int i=0;
    int size1=0;
    while(str1[i]!='\0'){
        if(str1[i]==' '){
            size1++;
            i++;
            continue;
        }
        i++;
    }
    size1=size1+1;
    int arr1[size1];
    int index=0;
    i=0;
    while(str1[i]!='\0'){
        if(str1[i]==' '){
            i++;
            continue;
        }
        if(isDigit(str1[i])==1){
            int num=0;
            while(isDigit(str1[i])==1){
                num=num*10 + str1[i]-'0';
                i++;
            }
            arr1[index++]=num;
        }
        i++;
    }

    i=0;
    int size2=0;
    while(str2[i]!='\0'){
        if(str2[i]==' '){
            size2++;
            i++;
            continue;
        }
        i++;
    }
    size2=size2+1;
    int arr2[size2];
    index=0;
    i=0;
    while(str2[i]!='\0'){
        if(str2[i]==' '){
            i++;
            continue;
        }
        if(isDigit(str2[i])==1){
            int num=0;
            while(isDigit(str2[i])==1){
                num=num*10 + str2[i]-'0';
                i++;
            }
            arr2[index++]=num;
        }
        i++;
    }

    mergeSort(size1,arr1,0,size1-1);
    mergeSort(size2,arr2,0,size2-1);
    int maximumMatching=calcMaximumMatching(size1,size2,arr1,arr2);
    printf("%d",maximumMatching);

    return 0;
}
