//insertion function using iteration (better for low systems memory)
void insert_iter(int d ,node**root){
if(*root==NULL){
    *root=get_node(d);
}
else{
node * ptr=*root ;
while(1){
    //if d is less than node's data & its left node isn't NULL we go left 
    if(d<=ptr->data&&ptr->left!=NULL){
        ptr=ptr->left;
    }
    //if d is larger than node's data & its right node isn't NULL we go right 
    else if(d>ptr->data&&ptr->right!=NULL){
        ptr =ptr->right;
    }
   //else we add the node
    else if(d<=ptr->data&&ptr->left==NULL){
        ptr->left=get_node(d);
        break;
    }
    else{
        ptr->right=get_node(d);
        break;
    }
}
}
}
