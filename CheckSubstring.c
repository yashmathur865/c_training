#include <stdio.h>
#include <string.h>

int main(){
    printf("Enter the string\n");
    char str[100];
    scanf("%[^\n]%*c",str);
    printf("Enter the substring to get its index\n");
    char sub[100];
    scanf("%[^\n]%*c",sub);
    int found=0;

    for(int i=0;i<strlen(str)-strlen(sub)+1;i++){
        int j;
        for(j=0;j<strlen(sub);j++){
            if(sub[j]!=str[i+j]){
                break;
            }
        }
        if(j==strlen(sub)){
            printf("%d",i);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("-1");
    }
    return 0;
}