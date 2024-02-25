#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to find the middle node of a linked list
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers, slow and fast, to the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow pointer by one step and fast pointer by two steps
        // When fast reaches the end of the list, slow will be at the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return the middle node
        return slow;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution sol;

    // Find the middle node of the linked list
    ListNode* middle = sol.middleNode(head);

    // Output the value of the middle node
    cout<<"Middle node value: "<< middle->val<<endl;

    return 0;
}