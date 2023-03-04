#include<stdio.h>
#include<stdlib.h>
int iter_bsearch(int x,int * arr,int size){
int start = 0 ;
int end = size-1;
while(start<=end){
int mid = start+(end-start)/2;//get mid index
if(arr[mid]==x){
    return mid  ;
}
else if(x<arr[mid]){
    end = mid-1 ;
}
else {
    start = mid+1;
}
}
return -1 ;
}
int rec_bsearch(int x,int *arr,int low,int high){
int mid = low+(high-low)/2;
if(low>high){
    return -1 ;
}
else if(arr[mid]==x){
    return mid ;
}
else if(x<arr[mid]){
    return rec_bsearch(x,arr,low,mid-1);
}
else {
    return rec_bsearch(x,arr,mid+1,high) ;
}
}

int main(){
int arr[] = {1,5,6,9,15,23,42,66} ;
int size = sizeof(arr)/sizeof(int);
printf("%d ",iter_bsearch(66,arr,size));
printf("%d ",rec_bsearch(14,arr,0,size));

return 0  ;
}
