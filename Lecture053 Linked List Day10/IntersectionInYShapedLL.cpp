// Intersection Point in Y Shaped Linked Lists
// Linked List 1 = 4->1->common
// Linked List 2 = 5->6->1->common
// common = 8->4->5->NULL
// Output: 8
// Explanation: 
//       5
//       |
// 4     6
// |     |
// 1     1
//  \   /
//    8  
//    |
//    4
//    |
//    5
//    |
//   NULL       

#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

vector<int> take(int n){
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>ans[i];
    return ans;
}

Node* inputList(int size, vector<int> v)
{
    if(size==0) return NULL;
    
    int val = v[0];
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        val = v[i+1];
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    srand(time(0));
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        int p = rand()%3;
        
        vector<int> v1 = take(n1);
        vector<int> v2 = take(n2);
        vector<int> v3 = take(n3);
        
        
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;
        
        if(p==0){
            common = inputList(n3, v3);
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
        }
        else if(p==1){
            
            head1 = inputList(n1, v1);
            common = inputList(n3, v3);
            head2 = inputList(n2, v2);
        }
         else{
            
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
            common = inputList(n3, v3);
        }
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2){
    if(head1==NULL || head2==NULL) 
       return -1;
    
    // find length of linked lists
    int l1 = length(head1);
    int l2 = length(head2);
    // set difference between length of Linked list 0
    int d = 0;
    // initialise two pointer at linked list head 
    Node* ptr1;
    Node* ptr2;
    // ptr1 pointer will point to head of linked list which has longest length
    if(l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    // then move ptr1 d times forward to get the intersection point
    while(d>0){
        ptr1 = ptr1->next;
        d--;
    }
    // move ptr1 & ptr2 one step forward simultaineously
    while(ptr1!=NULL && ptr2!=NULL){
        // if ptr1 & ptr2 points same node then return node data
        if(ptr1==ptr2)
          return ptr1->data;
          
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // if no intersection point found return -1
    return -1;
}

