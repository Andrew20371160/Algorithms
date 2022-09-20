#include<stdlib.h>
#include<stdio.h>

int min_index(int * arr ,  int s ){
int mini =0  ;
for(int i= 0 ; i <s ; i++){
    if(arr[mini]> arr[i+1] ){
        mini = i+1 ;
    }
}
return mini ;
}

void sort(int arr[],int sorted[] ,int s ){
for(int i = 0 ;i<s; i++){
sorted[i] = arr[min_index(arr,s)]  ;
arr[min_index(arr,s)] = 999999;

}
}

int main(){

int arr[] = {1,5,6,0,1,-8,66,7} ;
int s = sizeof(arr)/ sizeof(1) ;
int *arr2 = (int*) malloc(s*sizeof(int )) ;
sort(arr,arr2,s) ;
for(int i =0 ; i <s ;  i++){
    printf("%d ",arr2[i]) ;
}

return 0 ;
}
