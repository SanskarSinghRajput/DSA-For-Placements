#include<bits/stdc++.h>
using namespace std;
 
/* structure for a Node */
struct Node{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
}; 

void splitList(struct Node *head, struct Node **head1_ref,   struct Node **head2_ref);
struct Node* newNode(int key){
    struct Node *temp = new Node(key);
    
    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of the two resultant linked lists */

// function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.
void splitList(Node *head, Node **head1_ref, Node **head2_ref){
    // the resulting LL should also be circular   
    Node* slow = head;
    Node* fast = head;
    
    // finding mid
    while(fast->next!=head && fast->next->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }
      
    // point the start of the ll to head1_ref
    *head1_ref = head;
    
    // point head2_ref to the mid -> next
    *head2_ref = slow->next;
    
    // to make the head1_ref circular, point the end pointer to the head 
    slow->next = head;
    
    // if the head contains even number of elements we here make the head2_ref circular
    if(fast->next==head){
        fast->next = *head2_ref;
    }
    // if it is odd
    else{
        fast->next->next = *head2_ref;
    }
}

void printList(struct Node *head){
  struct Node *temp = head; 
  if(head != NULL){
    do{
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
  }
}

int main(){
  
   int t,n,i,x;
    scanf("%d",&t);
   while(t--)
   {
	   struct Node *temp,*head = NULL;
       struct Node *head1 = NULL;
       struct Node *head2 = NULL;
	   scanf("%d",&n);
	   scanf("%d",&x);
	   head=new Node(x);
	   temp=head;
	   for(i=0;i<n-1;i++){
	   scanf("%d",&x);
	   
	   temp->next=new Node(x);
	   
	   temp=temp->next;
	       
	   }
       
       temp->next=head;
  
       splitList(head, &head1, &head2);
  
     // printf("\nFirst Circular Linked List");
      printList(head1);  
 
     // printf("\nSecond Circular Linked List");
      printList(head2);  
   
   }
  return 0;
}