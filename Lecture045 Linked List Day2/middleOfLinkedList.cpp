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

// Function to calculate the length of a linked list
// Returns the length of the linked list
int getLength(Node* head) {
    int len = 0; // Initialize the length counter to 0

    // Traverse the linked list and count the number of nodes
    while (head != NULL) {
        len++; // Increment the length counter
        head = head->next; // Move to the next node
    }

    return len; // Return the length of the linked list
}

// Approach 1: Function to find the middle node of a linked list
// Returns a pointer to the middle node of the linked list
Node* getMiddle(Node* head) {
    int len = getLength(head); // Get the length of the linked list
    int midIndex = len / 2; // Calculate the index of the middle node

    Node* temp = head; // Initialize a temporary pointer to traverse the list
    int cnt = 0; // Initialize a counter to track the current position

    // Traverse the linked list until reaching the middle node
    while (cnt < midIndex) {
        temp = temp->next; // Move to the next node
        cnt++; // Increment the counter
    }

    return temp; // Return a pointer to the middle node
}

// Approach 2: (Optimize Approach) function to find the middle node of a linked list
// Returns a pointer to the middle node of the linked list
Node* getMiddle(Node* head) {
    // Check if the linked list is empty or contains only one node
    if (head == NULL || head->next == NULL) {
        return head; // Return the head node in these cases
    }

    // Check if the linked list contains only two nodes
    if (head->next->next == NULL) {
        return head->next; // Return the second node in this case
    }

    Node* slow = head; // Initialize a slow pointer to the head of the list
    Node* fast = head->next; // Initialize a fast pointer to the second node

    // Move the fast pointer two steps ahead and the slow pointer one step ahead
    while (fast != NULL) {
        fast = fast->next; // Move the fast pointer one step ahead
        if (fast != NULL) {
            fast = fast->next; // Move the fast pointer one step ahead again
        }
        slow = slow->next; // Move the slow pointer one step ahead
    }

    return slow; // Return the slow pointer which points to the middle node
}


Node *findMiddle(Node *head) { 
    // Optimize Approach
    return getMiddle(head);
      
}