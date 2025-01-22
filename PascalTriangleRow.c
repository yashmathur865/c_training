#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1");
        return 0;
    }
    int ans=1;
    printf("1,");
    for(int i=1;i<n-1;i++){
        ans*=(n-i);
        ans/=i;
        printf("%d,",ans);
    }
    printf("1");
    return 0;
}