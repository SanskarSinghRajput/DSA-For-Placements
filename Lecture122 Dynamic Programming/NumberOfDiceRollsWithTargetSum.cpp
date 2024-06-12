// 1155 Number Of Dice Rolls With Target Sum

class Solution {
public:
    const int mod = (int)pow(10, 9) + 7; 
    // Using Recusion
    int solve(int dice, int faces, int target){
        // base case
        if(dice == 0 && target == 0)
          return 1;
        if(dice == 0 || target <= 0)
          return 0;

        int ans = 0;
        for(int i = 1; i <= faces; i++){
            ans = ans + solve(dice-1, faces, target-i) % mod;
        }
        return ans% mod;
    }

    // Using Memoization - Top to Down
    int solveMem(int dice, int faces, int target, vector<vector<int>> &dp){
        // base case
        if(dice == 0 && target == 0)
          return 1;
        if(dice == 0 || target <= 0)
          return 0;

        if(dp[dice][target] != -1)
          return dp[dice][target] % mod;

        int ans = 0;
        for(int i = 1; i <= faces; i++){
            ans = (ans + solveMem(dice-1, faces, target-i, dp)) % mod;
        }
        dp[dice][target] = ans % mod;
        return dp[dice][target];
    }

    // Using Tabulation - Bottom to Up
    int solveTab(int d, int f, int t){
        vector<vector<int>> dp(d+1, vector<int> (t+1, 0));
        // after analysing base case
        dp[0][0] = 1;

        for(int dice = 1; dice <= d; dice++){
            for(int target = 1; target <= t; target++){
                int ans = 0;
                for(int i = 1; i <= f; i++){
                    if(target-i >= 0)
                       ans = (ans + dp[dice-1][target-i]) % mod;
                }
                dp[dice][target] = ans % mod;
            }
        }
        return dp[d][t];
    }

    // Using Tabulation with Space Optimization
    int solveTabSO(int d, int f, int t){
        vector<int> prev(t+1, 0);
        vector<int> curr(t+1, 0);
        // after analysing base case
        prev[0] = 1;

        for(int dice = 1; dice <= d; dice++){
            for(int target = 1; target <= t; target++){
                int ans = 0;
                for(int i = 1; i <= f; i++){
                    if(target-i >= 0)
                       ans = (ans + prev[target-i]) % mod;
                }
                curr[target] = ans % mod;
            }
            prev = curr;
        }
        return prev[t];
    }
    int numRollsToTarget(int n, int k, int target) {
        // return solve(n,k,target);

        // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        // return solveMem(n,k,target,dp);

        // return solveTab(n,k,target);

        return solveTabSO(n,k,target);
    }
};