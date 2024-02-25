// 21 Merge Two Sorted Lists
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
        // Check if either of the lists is empty.
        if(!list1)
            return list2;
        if(!list2)
            return list1;

        // Create a dummy node to hold the merged list.
        ListNode *ans = new ListNode(-1);
        // Pointer to traverse the merged list.
        ListNode *mptr = ans;

        // Loop until either of the lists reaches its end.
        while(list1 && list2){
            // If the value in list1 is less than or equal to the value in list2.
            if(list1->val <= list2->val){
                // Connect mptr to list1.
                mptr->next = list1;
                // Move mptr to list1.
                mptr = list1;
                // Move list1 to its next node.
                list1 = list1->next;
            }
            // If the value in list2 is less than the value in list1.
            else{
                // Connect mptr to list2.
                mptr->next = list2;
                // Move mptr to list2.
                mptr = list2;
                // Move list2 to its next node.
                list2 = list2->next;
            }
        }

        // If list1 has remaining nodes, connect them to the merged list.
        if (list1)
            mptr->next = list1;

        // If list2 has remaining nodes, connect them to the merged list.
        if (list2)
            mptr->next = list2;

        // Return the merged list starting from the next of the dummy node.
        return ans->next;
    }
};