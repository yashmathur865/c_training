#include<stdio.h>

int isDigit(char ch){
    if (ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int main(){
    char str[100];
    printf("Enter an IPv4 address\n");
    scanf("%s",str);

    int segment=0;
    int invalid=0;
    int i=0;

    while(str[i] != '\0'){
        if(str[i] == '.'){
            if(i==0 || str[i-1] == '.' || str[i+1]=='\0'){
                printf("Invalid\n");
                return 0;
            }
            i++;
            continue;
        }
        if(isDigit(str[i])==1){
            int num=0;
            int j=i;
            while(isDigit(str[i]) == 1 && str[i]!='\0'){
                num = num*10+(str[i]-'0');
                i++;
            }
            if(num != 0 && str[j]=='0' && i-j>1){
                printf("Invalid\n");
                return 0;
            }
            if(num >= 0 && num <= 255){
                segment++;
            }
            else {
                printf("Invalid\n");
                return 0;
            }
        }
        else{
            printf("Invalid\n");
            return 0;
        }
        if(str[i] != '.' && str[i] != '\0'){
            printf("Invalid\n");
            return 0;
        }
    }

    if(segment != 4){
        printf("Invalid\n");
        return 0;
    }

    printf("Valid\n");
    return 0;
}
