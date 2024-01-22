// Shortest path in Undirected Graph having unit distance
// You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and 
// if it is unreachable to reach any vertex, then return -1 for that vertex.

// Input:
// n = 9, m= 10
// edges=[[0,1],[0,3],[3,4],[4 ,5]
// ,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
// src=0
// Output:
// 0 1 2 1 2 3 3 4 4

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //create adjacency list
        vector<int> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //do bfs
        vector<int> visited(N, 0);
        queue<pair<int, int>> q;
        q.push({src, 0}); // push source node along with distance 0
        
        vector<int> distance(N, 1e9);
        distance[src] = 0;
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            int node = p.first;
            int dis = p.second; //distance of current node from the source node
            
            for(auto it : adj[node]){
                int d = dis + 1; // distance from source node to "it"
                distance[it] = min(d, distance[it]);
                if(!visited[it]){
                    q.push({it, dis+1});
                    visited[it] = 1;
                }
            }
        }
        
        for( int &d : distance){
            if(d == 1e9){
                d = -1;
            }
        }
        
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends