#include<stdio.h>
#include<string.h>

int main(){
    printf("Enter The String\n");
    char str[100];
    scanf("%s",str);
    char res[200];
    int index=0;

    int i=0;
    while(str[i]!='\0'){
        int count=1;
        res[index]=str[i];
        index++;
        while(str[i]==str[i+1]){
            count++;
            i++;
        }
        res[index++]=count + '0';
        i++;
    }

    res[index]='\0';
    if(strlen(res)<=strlen(str)){
        printf("%s",res);
    }
    else{
        printf("%s",str);
    }
    return 0;
}