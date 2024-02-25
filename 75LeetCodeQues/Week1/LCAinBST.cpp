// 235 Lowest Common Ancestor of a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Approch 1 (Recursive Approach)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is NULL, return NULL
        if(root == nullptr)
            return nullptr;
        
        // If both p and q are greater than root, LCA must be in the right subtree
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // If both p and q are smaller than root, LCA must be in the left subtree
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);  

        // If one of the nodes is found on the left subtree and the other on the right subtree,
        // or if one of the nodes is the current root, then root is the lowest common ancestor
        else
            return root;
    }

    // Approach 2 (Iterative Approach) More Optimized
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Traverse the tree until the root becomes NULL
        while(root != nullptr){
            // If both p and q are less than the current node's value, move to the left subtree
            if(root->val > p->val && root->val > q->val)
               root = root->left;
            
            // If both p and q are greater than the current node's value, move to the right subtree
            else if(root->val < p->val && root->val < q->val)
               root = root->right;
            
            // If the current node's value is between the values of p and q, or if one of them
            // is equal to the current node's value, then the current node is the lowest common ancestor
            else 
               return root;       
        }
        // If the root becomes NULL, return NULL (no common ancestor found)
        return nullptr;
    }
};