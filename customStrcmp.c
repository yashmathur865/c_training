#include <stdio.h>

int customStrcmp(const char *str1, const char *str2){
    while(*str1!='\0' && *str2!='\0'){
        if(*str1 != *str2){
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int main(){
    char string1[100],string2[100];
    printf("Enter first string: ");
    scanf("%s",string1);
    printf("Enter second string: ");
    scanf("%s",string2);

    int result=customStrcmp(string1, string2);
    if(result==0){
        printf("Strings are equal\n");
    }
    else if(result<0){
        printf("String 1 is lexicographically smaller than String 2\n");
    }
    else{
        printf("String 1 is lexicographically greater than String 2\n");
    }

    return 0;
}
