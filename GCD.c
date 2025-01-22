#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int computeGCD(int a,int b){
    if(b==0) return a;
    else{
        return computeGCD(b,a%b);
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a,b;
    scanf("%d %d",&a,&b);
    int gcd=computeGCD(a,b);
    printf("%d",gcd);
    return 0;
}
