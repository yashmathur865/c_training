#include<stdio.h>

int main(){
    printf("Enter The String\n");
    char str[100];
    scanf("%[^\n]%*c", str);

    int letterCount = 0;
    int maxcount = 0;
    int j = 0;
    int start = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ' || str[i] == '\0'){
            if(letterCount>maxcount){
                maxcount=letterCount;
                start = j;
            }
            letterCount = 0;
        }
        else{
            if(letterCount == 0){
                j=i;
            }
            letterCount++;
        }
    }

    if(letterCount>maxcount){
        maxcount=letterCount;
        start=j;
    }

    for(int i=start;i<start+maxcount;i++){
        printf("%c", str[i]);
    }

    return 0;
}
