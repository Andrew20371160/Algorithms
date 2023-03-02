#include <stdio.h>
#include <stdlib.h
#include <time.h>
void swap(int * n1 , int * n2 ){
int temp = *n1 ;
*n1 = *n2 ;
*n2 = temp ;
}
int  partition(int * arr,int start,int end ){
int pindex = start ;
int pivot = arr[end] ;
for(int i= start ;i<end; i++){
    if(arr[i]<=pivot ){
        swap((arr+i),(arr+pindex)) ;
        pindex++ ;
        }
    }

swap(arr+pindex,arr+end) ;
return pindex ;
}
int randpart(int *arr,int start,int end){
srand(time(NULL));
int pindex =rand()%(end-start);
swap(arr+end,arr+pindex);
return partition(arr,start,end);
}
void sort(int * arr,int start ,int end ){
if(start <end){
int pindex =randpart(arr,start,end) ;
sort(arr,start,pindex-1 ) ;
sort(arr,pindex+1,end);
}

}


int main()
{
int arr[10] = {9,3,1,0,2,4,5,6,7,8};
sort(arr,0,10) ;
for(int i = 0  ; i <10 ;i ++){
    printf("%d ",arr[i]) ;
}
    return 0;
}
