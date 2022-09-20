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


int main(){



return 0 ;
}
