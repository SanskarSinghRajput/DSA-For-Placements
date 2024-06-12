// 416 Partition Equal Subset Sum

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Using Recursion
    bool solve(int index, int arr[], int N, int target){
        if(index >= N)
          return 0;
        if(target < 0)
          return 0;
        if(target == 0)
          return 1;
          
        int include = solve(index+1, arr, N, target - arr[index]);
        int exclude = solve(index+1, arr, N, target - 0);
        
        return include or exclude;
    }
    
    // Using Memoization
     bool solveMem(int index, int arr[], int N, int target,vector<vector<int>> &dp){
        if(index >= N)
          return 0;
        if(target < 0)
          return 0;
        if(target == 0)
          return 1;
          
        if(dp[index][target] != -1)
           return dp[index][target];
         
        int include = solveMem(index+1, arr, N, target - arr[index], dp);
        int exclude = solveMem(index+1, arr, N, target - 0, dp);
        
        return dp[index][target] = include or exclude;
    }
    
    // Using Tabulation
    bool solveTab(int N, int arr[], int total){
        vector<vector<int>> dp(N+1, vector<int> (total+1, 0));
        
        for(int i = 0; i <= N; i++){
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                int include = 0;
                if(target - arr[index] >= 0)
                  include = dp[index+1][target - arr[index]];
                  
                int exclude = dp[index+1][target - 0];
        
                dp[index][target] = include or exclude;
            }
        }
        return dp[0][total/2];
    }
    
    // Using Tabulation with Space optimization
    bool solveTabSO(int N, int arr[], int total){
        // This will alse work use any of them as total or total/2
        // vector<int> curr(total+1, 0);
        // vector<int> next(total+1, 0);
        vector<int> curr(total/2+1, 0);
        vector<int> next(total/2+1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                int include = 0;
                if(target - arr[index] >= 0)
                  include = next[target - arr[index]];
                  
                int exclude = next[target - 0];
        
                curr[target] = include or exclude;
            }
            next = curr;
        }
        return next[total/2];
    }
    
    int equalPartition(int N, int arr[]){
        int total = 0;
        for(int i=0; i<N; i++)
           total += arr[i];
           
        if(total & 1)
          return 0;
           
        int target = total/2;
        // return solve(0,arr,N,target);
        
        // vector<vector<int>> dp(N, vector<int> (target+1, -1));
        // return solveMem(0,arr,N,target,dp);
        
        // return solveTab(N, arr, total);
        
        return solveTabSO(N, arr, total);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}