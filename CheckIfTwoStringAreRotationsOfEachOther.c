#include <stdio.h>
#include <string.h>

int main(){
    printf("Enter String 1\n");
    char str1[100];
    scanf("%[^\n]%*c",str1);
    printf("Enter String 2\n");
    char str2[100];
    scanf("%[^\n]%*c",str2);

    if(strlen(str1)!=strlen(str2)){
        printf("No string 2 is not rotation of String 1\n");
    }

    char temp[2*strlen(str1)+1];
    strcpy(temp,str1);
    strcat(temp,str1);

    int found=0;

    for(int i=0;i<strlen(temp)-strlen(str2)+1;i++){
        int j;
        for(j=0;j<strlen(str2);j++){
            if(str2[j]!=temp[i+j]){
                break;
            }
        }
        if(j==strlen(str2)){
            found=1;
            break;
        }
    }
    if(found==0){
        printf("No string 2 is NOT rotation of String 1\n");
    }
    else{
        printf("Yes string 2 is rotation of String 1\n");
    }

    return 0;
}