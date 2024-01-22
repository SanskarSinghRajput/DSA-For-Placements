#include <bits/stdc++.h> 
#define MOD 1000000007

int solve(long long nStairs,int i,vector<int>& dp){
    // base case
    if(i==nStairs)
      return 1;
    
    if(i>nStairs)
      return 0;
    //Step3
    if(dp[i]!=-1)
      return dp[i];
    // Step2
    dp[i]=(solve(nStairs,i+1,dp)+solve(nStairs,i+2,dp))%MOD; 
    return dp[i];
}
int countDistinctWays(long long nStairs) {
    // Memoization
    // Step1
    vector<int> dp(nStairs+1,-1);
    int ans=solve(nStairs,0,dp);
    return ans;
}