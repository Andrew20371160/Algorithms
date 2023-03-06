#include <stdio.h>
#include <stdlib.h>
int findx(int x ,int * arr, int size ){
int low = 0 ;
int high = size -1 ;
while(low<=high){
int mid = low+(high-low)/2 ;
if(arr[mid]==x){
    return mid  ;
}
else if(arr[mid]<=arr[high]){
    if(x<=arr[high]&&x>arr[mid]){
        low = mid +1 ;
    }
    else {
        high = mid -1 ;
    }
}
else{
    if(x>=arr[low]&&x<arr[mid]){
        high = mid -1  ;
    }
    else {
        low = mid +1 ;
    }
}
}
return -1 ;

}


int main()
{
int arr[] = {12,14,18,21,3,6,8,9};
int s =sizeof(arr)/sizeof(int) ;
printf("%d ",findx(12,arr,s));
printf("%d ",findx(14,arr,s));
printf("%d ",findx(18,arr,s));
printf("%d ",findx(21,arr,s));
printf("%d ",findx(3,arr,s));
printf("%d ",findx(8,arr,s));
printf("%d ",findx(9,arr,s));
printf("%d ",findx(1412,arr,s));


    return 0;
}
