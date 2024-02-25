// 110 Balanced Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isbalanced = true; // Variable to track if the tree is balanced

    // Function to calculate the height of a binary tree
    int height(TreeNode* root) {
        if(root == nullptr)
            return 0;

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Check if the tree is still balanced and update the status if not
        if(isbalanced && (abs(leftHeight - rightHeight) > 1))
            isbalanced = false;

        // Return the height of the current subtree
        return 1 + std::max(leftHeight, rightHeight);
    }

    // Function to check if a binary tree is balanced
    bool isBalanced(TreeNode* root) {
        // Calculate the height of the tree
        height(root);
        // Return whether the tree is balanced
        return isbalanced;
    }
};
