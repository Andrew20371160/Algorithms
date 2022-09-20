#include <stdio.h>
#include <stdlib.h>
void insertsort(int * arr,int s ){
int value , hole ;
for(int i = 1 ; i <s ; i++){
value = arr[i] ;
hole = i ;
while(arr[hole -1 ] >value && hole > 0 ){
    arr[hole] =  arr[hole-1 ] ;
    hole --;
}
arr[hole] = value  ;
}

}


int main()
{
int arr[] = {5,2,3,6,9,1,4,7,0,55} ;
int s  = sizeof(arr)/sizeof(1);
insertsort(arr,s) ;
for(int i= 0 ;i<s ;i++){
    printf("%d ",arr[i]);
}

    return 0;
}
