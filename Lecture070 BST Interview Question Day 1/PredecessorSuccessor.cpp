#include <bits/stdc++.h> 
/***********************************************************

	Following is the Binary Tree node structure:

	class binaryTreeNode{

	public :
		int data ;
		binaryTreeNode* left ;
		binaryTreeNode* right;

		binaryTreeNode(int data)
		{
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
	};

*********************************************************/

vector<int> findPreSuc(binaryTreeNode *root, int key){
	binaryTreeNode* temp = root;
	int pred = -1;
	int succ = -1;

    // Finding Key
	while(temp->data != key){
		if(temp->data < key){
		   pred = temp->data;
		   temp = temp->right;	
		}
		else{
			succ = temp->data;
			temp = temp->left;
		}
	}
    
	//  Finding Pred:
	binaryTreeNode* lefttree = temp->left;
	while(lefttree!=NULL){
		pred = lefttree->data;
		lefttree = lefttree->right;
	}

    //  Finding Succ:
	binaryTreeNode* righttree = temp->right;
	while(righttree!=NULL){
		succ = righttree->data;
		righttree = righttree->left;
	}
    vector<int> ans = {pred, succ};

    return ans;
}