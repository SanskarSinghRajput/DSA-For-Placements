// 543 Diameter of Binary Tree
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to calculate the height of the binary tree and update the diameter
    int height(TreeNode* root, int &D) {
        // Base case: if root is NULL, return 0
        if(root == nullptr)
            return 0;

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(root->left,D);
        int rightHeight = height(root->right,D);

        // Calculate the current diameter of the binary tree
        int diameter = leftHeight + rightHeight;

        // Update the overall diameter of the binary tree if necessary
        D = max(diameter, D);

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int D = 0; // Variable to store the diameter of the binary tree
        // Calculate the height of the binary tree
        height(root,D);

        // Return the diameter of the binary tree
        return D;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;

    // Find the diameter of the binary tree
    int diameter = sol.diameterOfBinaryTree(root);

    // Output the diameter of the binary tree
    cout<<"Diameter of the binary tree: "<<diameter<<endl;

    return 0;
}