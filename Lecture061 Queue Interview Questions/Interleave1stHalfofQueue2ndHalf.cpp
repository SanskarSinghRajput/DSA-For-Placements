// Interleave the First Half of the Queue with Second Half
// Input:
// N = 4
// Q = {2,4,3,1}
// Output:
// {2,3,4,1}
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // You are given a queue Q of N integers of even length
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> q1;
        int n = q.size();
        vector<int> ans;
        while(q.size() > n/2){
            int val = q.front();
            q.pop();
            q1.push(val);
        }
        
        while(q.size() != n && !q1.empty()){
            int val = q1.front();
            q1.pop();
            ans.push_back(val);
            val = q.front();
            q.pop();
            ans.push_back(val);
        }
        return ans;
    }

    // You are given a queue Q of N integers of odd length
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> q1;
        queue<int> q2;
        
        vector<int> ans;
        int s= q.size();
        
        for(int i=0;i<s;i++){
            int d=q.front();
            q.pop();
            if(i<s/2){
              
                q1.push(d);
            }
            else{
                q2.push(d);
            }
        }
        
        while(!q1.empty() && !q2.empty()){
            ans.push_back(q1.front());
            q1.pop();
            
            ans.push_back(q2.front());
            q2.pop();
        }
        
        while(!q1.empty()){
            ans.push_back(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            ans.push_back(q2.front());
            q2.pop();
        }
        
        return ans;
    }
};

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
