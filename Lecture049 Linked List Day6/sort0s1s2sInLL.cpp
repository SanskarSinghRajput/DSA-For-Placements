// Sort 0, 1, 2 in Linked list
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Approach 1
// Function to sort a linked list containing elements 0, 1, and 2
// Returns the head of the sorted list
Node* sortList(Node* head) {
    int zerocount = 0; // Count of 0s in the list
    int onecount = 0; // Count of 1s in the list
    int twocount = 0; // Count of 2s in the list
    Node* temp = head; // Pointer to traverse the list
    
    // Count the occurrences of 0s, 1s, and 2s in the list
    while (temp != NULL) {
        if (temp->data == 0)
            zerocount++;
        else if (temp->data == 1)
            onecount++;
        else if (temp->data == 2)
            twocount++;
        temp = temp->next; // Move to the next node
    }
    
    temp = head; // Reset temp to the head of the list
    
    // Update the list with sorted elements
    while(temp != NULL) {
        if (zerocount != 0) { // If there are remaining 0s
            temp->data = 0; // Update the current node's data to 0
            zerocount--; // Decrement the count of 0s
        } else if (onecount != 0) { // If there are remaining 1s
            temp->data = 1; // Update the current node's data to 1
            onecount--; // Decrement the count of 1s
        } else if (twocount != 0) { // If there are remaining 2s
            temp->data = 2; // Update the current node's data to 2
            twocount--; // Decrement the count of 2s
        }
        temp = temp->next; // Move to the next node
    }
    
    return head; // Return the head of the sorted list
}


void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}

// Approach 2
Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}



