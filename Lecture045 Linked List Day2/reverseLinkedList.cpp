#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
// Best Recursive Approach
Node* reverse1(Node*& head){
    if(head==NULL || head->next==NULL){
       return head;
    }
    Node* newhead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

// Recursive approach 1
void reverse(Node*& head,Node* curr,Node* prev){
    // base case
    if(curr==NULL){
        head=prev;
        return;
    }
    Node* forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}

// Iterative Approach
Node* reverse2(Node*& head){
    if(head==NULL || head->next==NULL){
       return head;
    }    
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

Node* reverseLinkedList(Node *head){
    // Best Approach
    return reverse1(head);

    // Recursive Approach
    Node* curr=head; 
    Node* prev=NULL;
    reverse(head,curr,prev);
    return head;
 
    // Iterative Approach
    return reverse2(head);  
}

