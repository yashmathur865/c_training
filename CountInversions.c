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

int CountAndMerge(int n,int arr[n],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];
    int res=0,i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            {arr[k++]=left[i++];}
        else{
            arr[k++]=right[j++];
            res=res+(n1-i);
        }
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];
    return res;
}

int CountInversions(int n,int arr[n],int l,int r){
    int res=0;
    if(l<r){
        int m=(l+r)/2;
        res+=CountInversions(n,arr,l,m);
        res+=CountInversions(n,arr,m+1,r);
        res+=CountAndMerge(n,arr,l,m,r);
    }
    return res;
}

int main() {

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
    int inversions;
    inversions=CountInversions(size,arr,0,size-1);
    printf("%d",inversions);
    return 0;
}
