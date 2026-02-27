#include <stdio.h>
int main(){
    int n,i,key,found;
    int arr[100];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter element to serch\n");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i] == key){
            printf("elemnt found at position %d\n",i+1);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("element not found\n");
    }
    return 0;
}
