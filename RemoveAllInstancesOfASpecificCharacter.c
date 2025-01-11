#include<stdio.h>

int main(){
    printf("Enter The String\n");
    char str[100];
    scanf("%[^\n]%*c",str);
    printf("Enter the character whose occurrences are to be removed\n");
    char a;
    scanf("%c",&a);

    int i=0;
    int j=0;
    while(str[i]!='\0'){
        if(str[i]!=a){
            str[j++]=str[i];
        }
        i++;
    }
    str[j]='\0';
    printf("%s",str);
}