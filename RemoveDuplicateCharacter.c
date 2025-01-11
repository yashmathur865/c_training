#include<stdio.h>

int main(){
    char str[100];
    scanf("%s",str);
    int arr[26]={0};
    char finalStr[100];
    int index=0;
    for(int i=0;str[i]!='\0';i++){
        if(arr[(str[i]-'a')]==1){
            continue;
        }
        else{
            finalStr[index]=str[i];
            index++;
            arr[(str[i]-'a')] = 1;
        }
    }
    finalStr[index]='\0';
    int i=0;
    while(finalStr[i]!='\0'){
        printf("%c",finalStr[i]);
        i++;
    }
    return 0;
}