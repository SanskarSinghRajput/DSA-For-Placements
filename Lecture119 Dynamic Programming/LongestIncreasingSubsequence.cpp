class Solution {
public:
    // Using Recursion
    int solve(int n, vector<int>& nums, int curr, int prev){
        // base case
        if(curr == n)
          return 0;

        // include
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev])
          take = 1 + solve(n, nums, curr + 1, curr);
        // exclude
        int notTake = 0 + solve(n,nums, curr+1, prev);
        
        return max(take,notTake);
    }

    // Using Memoization
    int solveMem(int n, vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        // base case
        if(curr == n)
          return 0;

        // prev+1 because when prev = -1 this index does not exist in dp vector so +1 in prev
        if(dp[curr][prev+1] != -1)
          return dp[curr][prev+1];

        // include
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev])
          take = 1 + solveMem(n, nums, curr + 1, curr, dp);
        // exclude
        int notTake = 0 + solveMem(n,nums, curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(take,notTake);
    }

    // Using Tabulation
    int solveTab(int n, vector<int>& nums){
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int curr = n-1; curr >= 0; curr--){
           for(int prev = curr-1; prev >= -1; prev--){
              // include
              int take = 0;
              if(prev == -1 || nums[curr] > nums[prev])
                take = 1 + dp[curr+1][curr+1];
              // exclude
              int notTake = 0 + dp[curr+1][prev+1];
        
              dp[curr][prev+1] = max(take, notTake);
           }
        }
        return dp[0][0];
    }
    
    // Using Tabulation using Space optimization
    int solveTab2(int n, vector<int>& nums){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--){
           for(int prev = curr-1; prev >= -1; prev--){
              // include
              int take = 0;
              if(prev == -1 || nums[curr] > nums[prev])
                take = 1 + nextRow[curr+1];
              // exclude
              int notTake = 0 + nextRow[prev+1];
        
              currRow[prev+1] = max(take, notTake);
           }
           nextRow = currRow;
        }
        return nextRow[0];
    }

    // DP with binary search
    int solveOptimal(int n, vector<int>& nums){
        if(n==0)
          return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n; i++){
            if(nums[i] > ans.back())
              ans.push_back(nums[i]);
            else{
                // find index of just bada element in ans
                int index = lower_bound(ans.begin(),ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(n,nums,0,-1);

        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solveMem(n,nums,0,-1,dp);

        // return solveTab(n, nums);

        // return solveTab2(n, nums);

        return solveOptimal(n, nums);
    }
};