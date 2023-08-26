#include <stdio.h>
#include <stdlib.h>
//Send Null pointer and this function will allocate memory while user is typing
char * get_input(char*str){
str =malloc(sizeof(char)) ;
*str = '\0' ;
unsigned int i = 0 ;
while((*(str+i)=getchar())!='\n'){
    i++;
    str = realloc(str,sizeof(char)*(i+1));
}
*(str+i)='\0';
return str ;
}

int main()
{
char *str = NULL ;
str  =get_input(str);
printf("\n%s",str) ;
free(str) ;str = NULL ;
    return 0;
}
