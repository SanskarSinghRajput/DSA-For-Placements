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
// Approach 2
// Optimize Approach
Node *getMiddle(Node *head) {
      if(head==NULL || head->next==NULL){
          return head;
      }
      // 2nodes are needed or not?
      if(head->next->next==NULL){
            return head->next;
      }
      Node* slow=head;
      Node* fast=head->next;
      while(fast!=NULL){ 
           fast=fast->next;
           if(fast!=NULL){
               fast=fast->next;
           }
           slow=slow->next;
      }
    return slow;
}
int getLength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

Node *findMiddle(Node *head) { 
    // Optimize Approach
    return getMiddle(head);
    
    // Approach 1
    int len=getLength(head);
    int ans=(len/2);
    
    Node* temp=head;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
}