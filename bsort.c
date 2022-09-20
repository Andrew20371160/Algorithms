#include <stdio.h>
#include <stdlib.h>

void bsort(int *arr ,int s ){
for(int i=0;i<s-1  ;i++){
    for(int j =i+1 ;j<s ;j++){
        if(arr[i]>arr[j]){
            int temp = arr[j] ;
            arr[j] = arr[i];
            arr[i] = temp ;
        }
    }
}


}

int main()
{
int n;
printf("\n enter number of elements ") ;
scanf("%d",&n) ;
int * arr= (int *) malloc(n*sizeof(int )) ;
for(int i =0 ; i <n; i++){
    printf("\n enter :");
    scanf("%d",arr+i) ;
}
bsort(arr,n) ;
printf("\n sorted :") ;
for(int i =0 ; i <n; i++){
    printf("%d ",*(arr+i));
}
free(arr) ;

return 0;

}
