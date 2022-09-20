#include <iostream>
const int s = 5 ;
using namespace std;
int minimum(int[] ,int );
int main()
{
int num[s];
cout<<"enter the numbers ";
for(int i = 0 ; i<s ;i++){

cin>>num[i];
}
int haha = minimum(num , s);

cout<<"the smallest number is "<<num[haha]<<endl ;
cout<<"and has the index of " <<haha ;




    return 0;
}
int minimum(int small[],int s){
int ind = 0 ;
int mini = small[0];
for(int i = 0 ; i<s ; i++){
    if(mini > small[i]){
    mini = small[i];
    ind = i ;


    }



}
return ind ;
}
