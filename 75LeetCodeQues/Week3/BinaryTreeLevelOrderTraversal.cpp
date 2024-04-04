class Solution
{
    public:
    // Approach 1 return list of levels of tree.
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
          return ans;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            //inner list to store curr lvl of elements
            vector<int> levelNodes;

            //Doing 2 steps
            for(int i=0;i<n;i++){
                //remove front after storing it
                Node* temp = q.front();
                q.pop();
                levelNodes.push_back(temp->data);

                //add next lvl elements
                if(temp->left)
                  q.push(temp->left);
                if(temp->right)
                  q.push(temp->right); 
            }
            ans.push_back(levelNodes);
        }
        return ans;        
    }
};