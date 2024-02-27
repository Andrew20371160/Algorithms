#include <iostream>
using namespace std ;

struct node{
int data ;
node *next ;
};
class List{
private :
node *head  ;
//helper function to allocate memory for new nodes
node *get_node(int data){
    node *new_node = new node ;
    new_node->data = data ;
    new_node->next = NULL ;
    return new_node ;
}
// This function returns a pointer to the node before the node with the minimum data in a linked list.
node *get_before_min(node *ptr){
    // Check if the list is not empty
    if(ptr){
        // Initialize a pointer to keep track of the node before the node with the minimum data
        node *before_min = ptr;
        // Initialize a pointer to traverse the list
        node *traverse_ptr = ptr;
        // Traverse the list
        while(traverse_ptr->next){
            // If the next node's data is less than or equal to the current minimum, update before_min
            if(traverse_ptr->next->data <= before_min->next->data){
                before_min = traverse_ptr;
            }
            // Move to the next node
            traverse_ptr = traverse_ptr->next;
        }
        // Return the node before the node with the minimum data
        return before_min;
    }
    // If the list is empty, return NULL
    return NULL;
}

public:
    //empty constructor
    List(){
        head = NULL ;
    }
    //initialize head with data constructor
    List(int data){
        head = new node ;
        head->data = data ;
        head->next = NULL ;
    }
    //initialize a whole list with a wanted size using data of an array (arr)
    List(int size , int *arr){
        head = get_node(arr[0]) ;
        node *ptr = head ;
        for(int i= 1;i<size ; i++){
            ptr->next = get_node(arr[i]) ;
            ptr = ptr->next ;
        }
    }
    //destructor to delete the whole list
    ~List(){
        node *ptr = head;
        while(head){
            ptr =ptr->next  ;
            delete [] head ;
            head = NULL;
            head = ptr ;
        }
    }
    //display function for testing
    void show(void){
        cout<<endl ;
        node*ptr = head  ;
        while(ptr){
            cout<<ptr->data<<" " ;
            ptr = ptr->next ;
        }
    }
// This function sorts a linked list in ascending order using the selection sort algorithm.
//this is better approach in sorting a list since you don't copy or replace data
//so better performacne overall
void sort_list(void){
    // Find the node before the node with the minimum data in the list
    node *before_min  = get_before_min(head);

    // Store the node with the minimum data
    node *mini= before_min->next;

    // If the node with the minimum data is not the head of the list, move it to the head
    if(before_min != head){
        // Update the links to move the node with the minimum data to the head of the list
        before_min->next = mini->next;
        mini->next = head;
        head = mini;
    }

    // Traverse the rest of the list
    node *ptr = head;
    while(ptr){
        // Find the node before the node with the minimum data in the rest of the list
        before_min = get_before_min(ptr);
        // If the node before the node with the minimum data is not the current node, move the node with the minimum data after the current node
        if(before_min != ptr){
            // Store the node with the minimum data
            mini = before_min->next;
            // Update the links to move the node with the minimum data after the current node
            before_min->next = mini->next;
            mini->next = ptr->next;
            ptr->next = mini;
        }

        // Move to the next node
        ptr = ptr->next;
    }
}
};

int main(){
int arr[]  = {1516,98,2,3,3,1};
List l1(sizeof(arr)/sizeof(int),arr) ;
l1.sort_list() ;
l1.show( );
return 0 ;
}
