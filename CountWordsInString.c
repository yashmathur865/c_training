#include<stdio.h>

int main() {
    printf("Enter the String:\n");
    char str[100];
    scanf("%[^\n]", str);

    int i = 0;
    int word_count = 0;
    int in_word = 0;

    while(str[i]!='\0'){
        if(str[i]==' '){
            i++;
            continue;
        }
        if(!in_word){
            word_count++;
            in_word = 1;
        }
        while(str[i]!=' ' && str[i]!='\0'){
            i++;
        }
        in_word = 0;
    }
    printf("Word count: %d\n", word_count);

    return 0;
}
