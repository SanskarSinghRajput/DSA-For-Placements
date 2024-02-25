// 70 ClimbingStairs.cpp

class Solution {
public:
    // // Using Recursion
    // int climbStairs(int n) {
    //     if(n<0)
    //       return 0;

    //     if(n==0)
    //       return 1;

    //     return climbStairs(n-1) + climbStairs(n-2);
    // }

    // Using DP
    int solve(int n, vector<int> &dp){
        if(n<=2)
           return n;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++)
           dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n,dp);
    }
};