#include<stdio.h>

int main(){
    printf("Enter String 1\n");
    char str1[100];
    scanf("%s",str1);
    printf("Enter Strinf 2\n");
    char str2[100];
    scanf("%s",str2);

    int arr[26]={0};
    for(int i=0;str1[i]!='\0';i++){
        arr[str1[i]-'a']++;
    }
    for(int i=0;str2[i]!='\0';i++){
        arr[str2[i]-'a']--;
    }

    int notAnagram=0;
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            notAnagram=1;
            break;
        }
    }

    if(notAnagram){
        printf("Given strings are not anagram of each other\n");
    }
    else{
        printf("Given strings are anagram of each other\n");
    }
}