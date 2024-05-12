#include<iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};
//allocate memory for a new node
node *get_node(int data){
    node* new_node = new node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node * get_tree(int* arr, int beg, int end){
    if(beg > end){//base condition
        return NULL;
    }
    //the root is the middle element
    //all left is less &&all right is bigger
    int mid = (beg+end)/2;
    node* root  = get_node(arr[mid]);
    //the left element is the middle in between
    //beg and position of the root
    root->left  = get_tree(arr, beg, mid - 1);
    //the right element is the middle in between
    //position of root and the end
    root->right = get_tree(arr, mid + 1, end);
    return root;
}
//display the tree
void show(node* root){
    if(root == NULL){
        return;
    }
    show(root->left);
    cout << root->data << " ";
    show(root->right);
}
//delete the tree
void del_tree(node* root){
    if(root == NULL){
        return;
    }
    del_tree(root->left);
    del_tree(root->right);
    delete root;
    root = NULL;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    node* root = get_tree(arr, 0, 15);
    show(root);
    cout << endl;
    del_tree(root);
    return 0;
}
