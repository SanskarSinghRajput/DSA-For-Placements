// 226 Invert Binary Tree
// Inverting a binary tree, also known as flipping or mirroring a binary tree, involves swapping 
// the left and right subtrees of every node in the tree.
    // Example
    //      4                         4
    //    /   \                     /   \
    //   2     7       =>          7     2
    //  / \   / \                 / \   / \
    // 1   3  6  9               9   6  3  1
    
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to invert the binary tree
    void invert(TreeNode* root) {
        // If the current node is NULL, return
        if (root == nullptr)
            return;

        // Swap the left and right subtrees of the current node
        TreeNode* swa = root->right;
        root->right = root->left;
        root->left = swa;

        // Recursively invert the left subtree
        invert(root->left);
        // Recursively invert the right subtree
        invert(root->right);
    }

    // Function to invert the entire binary tree
    TreeNode* invertTree(TreeNode* root) {
        // Call the invert function to invert the tree
        invert(root);
        // Return the root of the inverted tree
        return root;
    }
};

// Helper function to print the binary tree (inorder traversal)
void printTree(TreeNode* root) {
    if (root == nullptr)
        return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Creating an instance of the Solution class
    Solution sol;

    // Inverting the binary tree
    TreeNode* invertedRoot = sol.invertTree(root);

    // Printing the inverted binary tree
    std::cout << "Inverted Binary Tree: ";
    printTree(invertedRoot);
    std::cout << std::endl;

    return 0;
}
