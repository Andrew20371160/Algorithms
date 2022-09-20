#include <iostream>
#include<queue>
using namespace std;
struct node{
int data ;
node * left ;
node *right  ;
};
node * add_at_empty(int d ){
node * root = new node   ;
root ->data = d ;
root ->right  = NULL ;
 root ->left = NULL ;
 return root ;
}
node * add_in_order(int d , node *root ){
if(root == NULL){
    root =add_at_empty(d) ;

}
else if (d<root ->data){
    root ->left = add_in_order(d,root->left) ;

}
else {
    root ->right = add_in_order(d,root->right ) ;
}
return root ;
}
void levelorder(node * root ){
if(root ==NULL){
    return ;
}
queue<node*>q ;
q.push(root) ;
while(!q.empty()){
node * current = q.front() ;
cout<<current->data<<" ";
if(current->left !=NULL) q.push(current->left ) ;
if(current->right !=NULL) q.push(current->right ) ;
q.pop() ;

}

}



int main()
{
node * root = NULL ;
root =add_in_order(1,root ) ;
root =add_in_order(5,root ) ;
root =add_in_order(77,root ) ;
root =add_in_order(-9,root ) ;
root =add_in_order(66,root ) ;
levelorder(root) ;

    return 0;
}
