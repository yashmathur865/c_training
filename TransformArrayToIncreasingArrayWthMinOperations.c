#include <stdio.h>

int minOperationsToIncreasing(int arr[],int n){
    int operations = 0;
    for(int i=1;i<n;i++){
        if(arr[i]<=arr[i-1]){
            int diff=(arr[i - 1]+1) - arr[i];
            arr[i]=arr[i - 1] + 1;
            operations += diff;
        }
    }
    return operations;
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int result = minOperationsToIncreasing(arr,n);
    printf("Minimum operations required: %d\n",result);
    return 0;
}
