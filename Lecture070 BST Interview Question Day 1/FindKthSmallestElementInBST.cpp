#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
// method 1
int solve(BinaryTreeNode<int>* root, int &i, int k){
    if(root==NULL)
        return -1;
    
    //L
    int left=solve(root->left,i,k);

    if(left!=-1){
        return left;
    }
    //N
    i++;
    if(i==k)
       return root->data;

    // R
    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    int ans = solve(root,i,k);
    return ans;
}

// method 2
void solve(Node *root,int &i,int K,int &ans){
    if(root==NULL)
        return ;
        
    // L 
    solve(root->left,i,K,ans);
    
    // N
    i++;
    if(i==K)
        ans = root->data;
        
    // R
    solve(root->right,i,K,ans);
}
// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K) {
    int i = 0;
    int ans = -1;
    solve(root,i,K,ans);
    return ans;
}