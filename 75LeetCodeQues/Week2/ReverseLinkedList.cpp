// 206. Reverse Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // If the list is empty, return NULL
        if (head == nullptr)
            return nullptr;

        ListNode* curr = head; // Pointer to the current node
        ListNode* prev = nullptr; // Pointer to the previous node(initialized to NULL)
        ListNode* forward = nullptr; // Pointer to the next node

        // Iterate through the list and reverse the pointers
        while (curr != nullptr) {
            forward = curr->next; // Store the next node
            curr->next = prev; // Reverse the pointer to the previous node
            prev = curr; // Move prev pointer to the current node
            curr = forward; // Move curr pointer to the next node
        }

        // At the end of the loop, prev will be pointing to the new head
        // of the reversed list
        return prev; // Return the head of the reversed list
    }
};