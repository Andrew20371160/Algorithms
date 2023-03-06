#include<stdio.h>
#include<stdlib.h>
int rotationcount(int *arr, int size){
int low = 0 ;
int high = size -1  ;
while(low<=high){
    if(arr[low]<arr[high]){
        return low ;
    }
    int mid = low +(high-low)/2 ;
    int prev = (mid-1+size)%size ;
    int next = (mid+1)%size ;
    if(arr[next]>arr[mid]&&arr[prev]>arr[mid]){
        return mid  ;
    }
    else if(arr[mid]<arr[high]){
        high = mid -1 ;
    }
    else {
        low = mid+1 ;
    }
}
return -1 ;
}


int main(){
int arr[] = {3,5,8,11,12,2};
int size = sizeof(arr)/sizeof(int);
printf("%d ",rotationcount(arr,size)) ;

return 0;
}
