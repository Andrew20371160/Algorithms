#include <stdio.h>
#include <stdlib.h>

int count  =  0  ;
int * arr= NULL ;

void add(int d){
if(arr==NULL){
    arr = (int*)malloc(sizeof(int)) ;
    *arr = d ;
}
else{
    arr = (int*)realloc(arr,(count+1)*(sizeof(int)));
    *(arr+count) = d;
}
count++ ;
}

void show(){
if(arr==NULL){
    printf("\nEmpty") ;
}
for( int i = 0 ; i <count ; i++){
    printf("%d ",*(arr+i)) ;
}
}

int main()
{

for(int i = 0 ; i<10;i++){
    add(i);
}
show() ;
free(arr) ;
arr =NULL ;
    return 0;
}
