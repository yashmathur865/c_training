#include <stdio.h>

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    printf("Enter the string: ");
    char str[100];
    scanf("%s", str);

    int i=0,num=0,sign=1;
    int hasNumberStarted = 0;

    while (str[i] != '\0') {
        if (str[i] == '-' && !hasNumberStarted){
            sign = -1;
            i++;
            continue;
        }
        if (isDigit(str[i])) {
            hasNumberStarted = 1;
            while (isDigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            num *= sign;
        }
        if (str[i] != '\0' && !isDigit(str[i])) {
            printf("Invalid input\n");
            return 0;
        }
        i++;
    }

    if(hasNumberStarted){
        printf("Parsed number: %d\n", num);
    } else {
        printf("No valid number found\n");
    }

    return 0;
}
