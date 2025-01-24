#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void seq_generator(int n_index,int k_index,int n,int k,int seq_arr[k]){
    if(k_index>=k){
        for(int i=0;i<k;i++){
            printf("%d ",seq_arr[i]);
        }
        printf("\n");
        return;
    }

    if(n_index>n){
        return;
    }
    seq_arr[k_index]=n_index;

    seq_generator(n_index+1,k_index+1,n,k,seq_arr);

    seq_arr[k_index]=0;

    seq_generator(n_index+1,k_index,n,k,seq_arr);
    return;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int k,n;

    scanf("%d",&k);
    scanf("%d",&n);

    int seq_arr[k];

    seq_generator(1,0,n,k,seq_arr);
    return 0;
}