#include <stdlib.h>
#include <stdio.h>
typedef long uint32;
//node structure
typedef struct {
int data ;
struct node * next ;
}node;
//get memory for a new node
node * get_node(int data){
node * new_node= malloc(sizeof(node)) ;
new_node->data = data ;
new_node->next = NULL ;
return new_node ;
}
//add a node at the beginning of the list O(1)
void add_at_beg(node**head,int data){
if(*head==NULL){
    *head = get_node(data);
}
else{
node * new_node=  get_node(data);
new_node->next = *head ;
*head =  new_node ;
}
}
//merging 2 lists into one (head) 
void merge(node *left ,node *right,node **head){
node *pleft = left ;
node *pright = right ;
node *phead = *head ;
while(pleft&&pright){
    if(pleft->data<pright->data){
        phead->data = pleft->data ;
        pleft= pleft->next;
    }
    else{
        phead->data =pright->data ;
        pright= pright->next ;
    }
    phead=  phead->next ;
}
while(pleft){
    phead->data = pleft->data ;
    phead =phead->next ;
    pleft  = pleft->next ;
}
while(pright){
    phead->data = pright->data ;
    phead = phead ->next ;
    pright=  pright->next ;
}
delall(&left) ;
delall(&right) ;
}
//returns size of a list 
uint32 list_size(node *head){
uint32 counter = 0 ;
while(head){
    head=head->next;
    counter++;
}
return counter ;
}
//dividing the list into 2 halves untill you are left with 2 separate elements
void merge_sort(node **head){
uint32 size  = list_size(*head);
if(size>1){
node *left = NULL;
node *right = NULL ;
node *phead= *head ;
for(uint32 i= 0 ; i<size/2;i++){
add_at_beg(&left,phead->data);
phead= phead->next;
}
for(uint32 i=size/2; i<size; i++){
add_at_beg(&right,phead->data);
    phead=phead->next ;
}
    
merge_sort(&left);
merge_sort(&right);
merge(left,right,head) ;
}
}
//delete the lists so no memory leaks 
void delall(node **head){
    node * second = (*head)->next ;
    while(second!=NULL){
    free(*head) ;
    *head = NULL ;
    *head = second ;
    second= second->next ;
}
if(*head){
free(*head) ; *head = NULL ;
}
}
void show_list(node *ptr){
puts("");   
while(ptr){
    printf("%d ",ptr->data);
    ptr = ptr->next ;
}
}
void main(void){
node *head = NULL;
add_at_beg(&head,15);
add_at_beg(&head,1);
add_at_beg(&head,11);
add_at_beg(&head,12);
add_at_beg(&head,-5);
add_at_beg(&head,65);
add_at_beg(&head,150);
add_at_beg(&head,155);
add_at_beg(&head,15455);
add_at_beg(&head,1133);
show_list(head); 
merge_sort(&head);
show_list(head) ; 
}
