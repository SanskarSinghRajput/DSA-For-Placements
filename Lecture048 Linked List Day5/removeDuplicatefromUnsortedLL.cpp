// Remove Duplicate From Unsorted Linked List

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
      data = x;
      next = NULL;
    }
};

void print(Node *root){
    Node *temp = root;

    while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
    }
}

class Solution{
  public:
    // Function to remove duplicates from an unsorted linked list
    // Returns the head of the modified list with unique elements
    Node* removeDuplicates(Node* head) {
        unordered_map<int, bool> visited; // Hash map to keep track of visited elements
        Node* temp = head; // Pointer to traverse the list
        Node* prev = head; // Pointer to keep track of the previous node
        
        // Traverse the list
        while(temp != NULL) {
            // Check if the current node's data has been visited before
            if(visited[temp->data] != true) {
                visited[temp->data] = true; // Mark the current node's data as visited
                prev = temp; // Update the previous node to the current node
                temp = temp->next; // Move to the next node
            } 
            else{
                // If the current node's data is a duplicate
                prev->next = temp->next; // Skip the current node by updating the previous node's next pointer
                temp = prev->next; // Move to the next node
            }
        }    
        return head; // Return the head of the modified list with unique elements
    }
};


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--){
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
