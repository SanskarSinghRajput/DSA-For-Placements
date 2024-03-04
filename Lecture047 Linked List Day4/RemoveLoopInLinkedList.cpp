// The Tortoise and Hare algorithm detects the loop in a linked list by using two pointers one slow (tortoise) and one fast (hare), 
// where the slow pointer moves one step at a time and the fast pointer moves two steps at a time. 
// When they meet, the loop is detected, and to remove the loop, one pointer is moved back to the head of the list while both
// pointers move one step at a time until they meet at the point where the loop begins, then the next pointer is set to null.

// Floyd's Tortoise and Hare algorithm
// Returns the node where the loop is detected or NULL if no loop is found
Node* floydDetectLoop(Node* head) {
    // If the linked list is empty, return NULL
    if (head == NULL)
        return NULL;

    // Initialize two pointers, slow and fast, both starting from the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list using the slow and fast pointers
    while (slow != NULL && fast != NULL) {
        fast = fast->next; // Move fast pointer one step ahead
        if (fast != NULL) {
            fast = fast->next; // Move fast pointer one step ahead again
        }

        slow = slow->next; // Move slow pointer one step ahead

        // If slow and fast pointers meet, it indicates the presence of a loop
        if (slow == fast) {
            return slow; // Return the meeting point means Loop is present
        }
    }
    // If the loop exits without detecting a loop, return NULL
    return NULL;
}

// Returns the starting node of the loop or NULL if no loop is found
Node* getStartingNode(Node* head) {
    // If the linked list is empty, return NULL
    if (head == NULL)
        return NULL;

    // Find the intersection point using the Floyd's Tortoise and Hare algorithm
    Node* intersection = floydDetectLoop(head);

    // If no loop is found, return NULL
    if (intersection == NULL)
        return NULL;

    // Initialize a pointer slow starting from the head of the linked list
    Node* slow = head;

    // Traverse the linked list until slow and intersection meet
    while (slow != intersection) {
        slow = slow->next; // Move slow pointer one step ahead
        intersection = intersection->next; // Move intersection pointer one step ahead
    }

    // Return the starting node of the loop
    return slow;
}


// Returns the head of the linked list after removing the loop
Node* removeLoop(Node* head) {
    // If the linked list is empty, return NULL
    if (head == NULL)
        return NULL;

    // Find the starting node of the loop, if present
    Node* startOfLoop = getStartingNode(head);

    // If no loop is found, return the original head of the linked list
    if (startOfLoop == NULL)
        return head;

    Node* temp = startOfLoop; // Initialize a pointer temp to the starting node of the loop

    // Traverse the loop until the last node before the starting node of the loop
    while (temp->next != startOfLoop) {
        temp = temp->next; // Move temp pointer to the next node
    } 

    temp->next = NULL; // Set the next pointer of the last node before the loop to NULL to break the loop

    return head; // Return the head of the linked list after removing the loop
}