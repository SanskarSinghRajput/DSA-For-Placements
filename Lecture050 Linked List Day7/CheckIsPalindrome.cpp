class Solution{
  private:
    Node* getMid(Node* head ) {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        Node* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->data != head1->data) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2 reverse List after Middle to make Linked List back to original
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }

    // Approach 1
    // Function to check if a linked list is a palindrome
    // Returns true if the linked list is a palindrome, false otherwise
    bool isPalindrome(Node* head) {
        vector<int> v; // Vector to store elements of the linked list
        Node* curr = head; // Pointer to traverse the linked list
        
        // Traverse the linked list and store its elements in the vector
        while (curr != NULL) {
            v.push_back(curr->data); // Store the current node's data in the vector
            curr = curr->next; // Move to the next node
        }
        
        int n = v.size(); // Size of the vector (number of elements in the linked list)
        
        // Check if the linked list is a palindrome by comparing elements from both ends of the vector
        for (int i = 0; i < n; i++) {
            if (v[i] != v[n - 1 - i]) // If the elements at symmetric positions do not match
                return false; // The linked list is not a palindrome
        }
        
        return true; // If all elements match, the linked list is a palindrome
    }


};