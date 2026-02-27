#include <stdio.h>
int main(){
    int n,i;
    int arr[100];
    int min,pos;

    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    min=arr[0];
    pos=0;

    for(i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
            pos=i;
        }
    }
    printf("Minimum element is %d, found at position %d\n",min,pos+1);
    return 0;
}
