// Returns true if the linked list is circular, false otherwise
bool isCircularList(Node* head) {
    // If the linked list is empty, it is considered circular
    if (head == NULL) {
        return true;
    }

    // Initialize a pointer temp to the next node after the head
    Node* temp = head->next;

    // Traverse the linked list until the end or until temp points back to the head
    while (temp != NULL && temp != head) {
        temp = temp->next; // Move temp pointer to the next node
    }

    // If temp points back to the head, it indicates a circular linked list
    if (temp == head) {
        return true;
    }

    // If temp reaches the end of the linked list without pointing back to the head, it is not circular
    return false;
}