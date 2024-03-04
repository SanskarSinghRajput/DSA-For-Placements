// Remove duplicates from a sorted linked list
/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

// Function to remove duplicates from a sorted linked list
// Returns the head of the modified list with unique elements
Node* uniqueSortedList(Node* head) {
    // Check if the list is empty
    if (head == NULL)
        return NULL; // Return NULL if the list is empty
    
    // Initialize a pointer to traverse the list
    Node* curr = head;

    // Traverse the list
    while (curr != NULL) {
        // Check if the current node has a next node and if their data is equal
        if ((curr->next != NULL) && (curr->data == curr->next->data)) {
            // If duplicates are found, remove the next node
            Node* next_next = curr->next->next; // Store the next of next node
            Node* nodeToDelete = curr->next; // Store the node to delete
            delete(nodeToDelete); // Delete the duplicate node
            curr->next = next_next; // Update the next pointer of the current node
        } else {
            // If the current node and the next node are not duplicates, move to the next node
            curr = curr->next;
        }
    }

    return head; // Return the head of the modified list with unique elements
}