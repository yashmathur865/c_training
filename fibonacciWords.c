#include <stdio.h>
#include <string.h>

void FindNthFibonacci(int n, char *result) {
    if(n==0){
        strcpy(result,"0");
        return;
    }
    if(n==1){
        strcpy(result,"01");
        return;
    }

    char prev1[10000],prev2[10000];
    FindNthFibonacci(n - 1, prev1);
    FindNthFibonacci(n - 2, prev2);

    strcpy(result, prev1);
    strcat(result, prev2);
}

int main(){
    printf("Enter the value of n: ");
    int n;
    scanf("%d", &n);

    char result[10000];

    FindNthFibonacci(n, result);
    printf("The %d-th Fibonacci word is:\n%s\n",n,result);

    return 0;
}
