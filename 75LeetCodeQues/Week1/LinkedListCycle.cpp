// 141 Linked List Cycle
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
    // (Best Approach) Approach 1 Using Two Pointer
    bool hasCycle(ListNode *head) {  
        // making two pointers fast and slow & assigning them to head
        ListNode* slow = head;
        ListNode* fast = head;

        // till fast and fast->next not reaches NULL
        // we will increment fast by 2 step and slow by 1 step
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            // At the point if fast and slow are at the same address
            // this means linked list has a cycle in it 
            if(fast==slow)
              return true; 
        }
        // if traversal reaches to NULL this means no cycle present
        return false;
    }
    
    // Approach 2 Using Set Hash Table
    bool hasCycle(ListNode *head) { 
        unordered_set<ListNode*> visited_node;
        ListNode *curr = head;
        while(curr != NULL){
            // If the current Node is present in set means cycle is present
            if(visited_node.find(curr) != visited_node.end())
               return true;

            // If the current Node is not present in set insert it into set
            visited_node.insert(curr);
            curr = curr->next;
        } 
        // if traversal reaches to NULL this means no cycle present
        return false;
    }

    // Approach 3 Using Map
    bool hasCycle(ListNode *head) { 
        unordered_map<ListNode*, bool> mp;
        ListNode* curr = head;
        while(curr != NULL){
            if(mp[curr])
              return true;

            mp[curr] = true;
            curr = curr->next;
        }
        return false;
    }

};

int main() {
    // Creating a sample linked list with a cycle
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head; // Creating a cycle

    // Creating an instance of the Solution class
    Solution sol;

    // Checking if the linked list has a cycle
    bool hasCycle = sol.hasCycle(head);

    // Printing the result
    if (hasCycle)
        std::cout << "The linked list has a cycle." << std::endl;
    else
        std::cout << "The linked list does not have a cycle." << std::endl;

    return 0;
}