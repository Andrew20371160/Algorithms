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
void delall(struct node **head){
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
