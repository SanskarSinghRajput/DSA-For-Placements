/*******   Detect Cycle in Linked List    *******/
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

// Approach 1 Using a map to mark visited nodes
bool detectLoop(Node* head) {
    if(head == NULL)
        return false;

    map<Node*, bool> visited; // Map to store visited nodes and their status

    Node* temp = head; // Temporary pointer to traverse the linked list

    while(temp != NULL) {
        // If the current node is already marked as visited, a cycle is present
        if(visited[temp] == true) {
            // Print the data of the node where the cycle is detected
            cout << "Present on element " << temp->data << endl; 
            return true; // Return true indicating the presence of a cycle
        }

        visited[temp] = true; // Mark the current node as visited
        temp = temp -> next; // Move to the next node
    }
    return false; // If loop exits without detecting a cycle, return false
}

// Approach 2 Using  Floyd's Tortoise and Hare algorithm
bool detectLoop(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false; // No cycle if the list is empty or has only one node
    }

    ListNode *slow = head; // Tortoise pointer
    ListNode *fast = head; // Hare pointer

    // Move the slow pointer one step and the fast pointer two steps at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If the pointers meet, it means there is a cycle in the list
        if (slow == fast) {
            return true;
        }
    }

    return false; // If fast reaches the end (NULL), there is no cycle
}


