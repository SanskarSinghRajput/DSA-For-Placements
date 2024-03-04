// Reverse every k nodes of a linked list

// Function to reverse every k nodes of a linked list
// Returns the head of the modified linked list after reversing every k nodes
Node* kReverse(Node* head, int k) {
    // Base case: If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }
    
    // Step 1: Reverse the first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Step 2: Recursively process the remaining list (if any) and get the head of the reversed sublist
    if (next != NULL) {
        head->next = kReverse(next, k);
    }
    
    // Step 3: Return the head of the reversed list
    return prev;
}
