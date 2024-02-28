// 104 Maximum Depth(Height) of Binary Tree
#include<bits/stdc++.h>
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
    // Function to find the maximum depth of a binary tree
    int maxDepth(TreeNode* root) {  
        // If the root is NULL, the depth of the current subtree is 0
        if(root == nullptr)
           return 0;

        // Recursively calculate the maximum depth of the left subtree
        int leftH = maxDepth(root->left);

        // Recursively calculate the maximum depth of the right subtree
        int rightH = maxDepth(root->right);

        // Calculate the maximum depth of the current subtree by adding 1 to the maximum depth of its left and right subtrees
        int ans = 1 + max(leftH, rightH);

        // Return the maximum depth of the current subtree
        return ans;
    }
};
