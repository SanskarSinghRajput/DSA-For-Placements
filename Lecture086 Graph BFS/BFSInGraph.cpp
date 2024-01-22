#include<bits/stdc++.h>
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    queue<int> q;
    q.push(0);
    int visited[n+1] = {0};
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // store node into ans
        ans.push_back(node);
        
        // traverse all neighbours of node
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}