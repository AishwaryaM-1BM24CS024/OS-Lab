#include <stdio.h>
int main(){
    int n,i,key,found;
    int low,high,mid;
    int arr[100];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter element to serch\n");
    scanf("%d",&key);
    low=0;
    high=n;
    while(low <= high){
        mid=(high+low)/2;
        if(arr[mid]==key){
            printf("elemnt found at position %d\n",mid+1);
            found=1;
            break;
        }
        else if(arr[mid] <key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(found==0){
        printf("element not found\n");
    }
    return 0;
}
