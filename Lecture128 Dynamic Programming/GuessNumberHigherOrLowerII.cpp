// 375. Guess Number Higher or Lower II

/* We are playing the Guessing Game. The game will work as follows:

1. I pick a number between 1 and n.
2. You guess a number.
3. If you guess the right number, you win the game.
4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and
 you will continue guessing.
5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.

Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what 
number I pick. */


class Solution {
public:
    // Recursive 
    int solve(int start, int end){
        if(start >= end)
          return 0;
        
        int maxi = INT_MAX;
        for(int i=start; i<=end; i++){
            maxi = min(maxi, i+max(solve(start,i-1), solve(i+1,end)));
        }
        return maxi;
    }

    // Memoization
    int solveMem(int start, int end, vector<vector<int>> &dp){
        if(start >= end)
          return 0;

        if(dp[start][end] != -1)
          return dp[start][end];
        
        int maxi = INT_MAX;
        for(int i=start; i<=end; i++){
            maxi = min(maxi, i+max(solveMem(start,i-1,dp), solveMem(i+1,end,dp)));
        }
        return dp[start][end] = maxi;
    }

    int solveTab(int n){
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int start=n; start>=1; start--){
           for(int end=start; end<=n; end++){
              if(start == end)
                continue;
              else{
                  int maxi = INT_MAX;
                  for(int i=start; i<=end; i++){
                     maxi = min(maxi, i+max(dp[start][i-1],dp[i+1][end]) );
                  }
                  dp[start][end] = maxi;
              }
           }
        }
        return dp[1][n];
    }
    
    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solveMem(1, n, dp);

        return solveTab(n);
    }
};