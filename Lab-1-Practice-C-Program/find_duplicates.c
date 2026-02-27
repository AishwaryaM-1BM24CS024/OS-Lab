#include <stdio.h>
int main(){
    int n,i,j,found=0;
    int arr[100];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("enter elemnets\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
                printf("duplicate exist. duplicate element is %d\n",arr[i]);
                found=1;
            }
        }

    }
    if(!found){
        printf("No duplicates exist");
    }
    return 0;

}
