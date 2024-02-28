// 98 Validate Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to check if the binary search tree (BST) rooted at "root" is valid within the specified range [mini, maxi]
    bool check(TreeNode* root, long mini, long maxi) {
        // If the current node is NULL, it's a valid BST
        if (root == NULL)
            return true;

        // Check if the value of the current node is within the valid range
        // [mini, maxi]
        if (root->val > mini && root->val < maxi) {
            // Recursively check the left subtree with the updated maximum value
            // as the value of the current node
            bool left = check(root->left, mini, root->val);
            // Recursively check the right subtree with the updated minimum
            // value as the value of the current node
            bool right = check(root->right, root->val, maxi);
            // Return true if both left and right subtrees are valid BSTs
            return left && right;
        } 
        else {
            // If the value of the current node is not within the valid range,
            // it's not a valid BST
            return false;
        }
    }

    // Function to check if the binary tree rooted at "root" is a valid BST
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        // Call the helper function "check" with the root node and the range
        // [LONG_MIN, LONG_MAX]
        return check(root, LONG_MIN, LONG_MAX);
    }
};
