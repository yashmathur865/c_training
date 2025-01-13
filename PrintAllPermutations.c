#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

void permute(char *str,int left,int right){
    if(left==right){
        printf("%s\n", str);
        return;
    }

    for (int i=left;i<=right;i++){

        swap(&str[left], &str[i]);

        permute(str, left + 1, right);

        swap(&str[left], &str[i]);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int length=strlen(str);
    printf("All permutations of the string are:\n");
    permute(str,0,length - 1);

    return 0;
}
