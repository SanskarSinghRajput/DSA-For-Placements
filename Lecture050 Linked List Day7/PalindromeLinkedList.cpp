// 234. Palindrome Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to find the middle node of a linked list
    ListNode* getMid(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* slow = head; // Slow pointer initially points to head
        ListNode* fast = head; // Fast pointer initially points to head

        // Move the fast pointer twice as fast as the slow pointer
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; // Move fast pointer two steps ahead
            slow = slow->next;       // Move slow pointer one step ahead
        }

        // At this point, slow points to the middle node of the linked list
        return slow;
    }

    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head; // Current pointer initially points to head
        ListNode* prev = NULL; // Previous pointer initially points to NULL
        ListNode* next = NULL; // Next pointer initially points to NULL

        // Reverse the pointers of each node in the linked list
        while (curr != NULL) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the pointer of the current node
            prev = curr;       // Move prev pointer to the current node
            curr = next;       // Move curr pointer to the next node
        }

        // At this point, prev points to the new head of the reversed list
        return prev;
    }

    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        // An empty list or a list with only one node is a palindrome
        if(head == NULL || head->next == NULL)
            return true; 

        // Step1: Find Middle of Linked List 
        // Find the middle node of the linked list
        ListNode* mid = getMid(head);
        
        // Head of the first half of the list
        ListNode* head1 = head; 

        // Head of the second half of the list (reversed)
        // Step2: Reverse List from mid
        ListNode* head2 = reverse(mid); 

        // Step3: Compare elements of both halves of the list
        while(head2 != NULL) {
            // If elements don't match, the list is not a palindrome
            if(head1->val != head2->val)
                return false; 

            head1 = head1->next; // Move head1 to the next node
            head2 = head2->next; // Move head2 to the next node
        }
        return true; // If all elements match, the list is a palindrome
    }
};