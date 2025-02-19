#include <bits/stdc++.h> 
int solveRec(vector<int> &nums,int n){
    //base case
    if(n<0)
      return 0;
    if(n==0)
      return nums[0];

    int incl = solveRec(nums,n-2) + nums[n];
    int excl = solveRec(nums,n-1) + 0;

    return max(incl,excl);
}
int solveMem(vector<int> &nums,int n,vector<int> &dp){
    //base case
    if(n<0)
      return 0;
    if(n==0)
      return nums[0];

    if(dp[n]!=-1)
      return dp[n];

    int incl = solveMem(nums,n-2,dp) + nums[n];
    int excl = solveMem(nums,n-1,dp) + 0;
    dp[n] = max(incl,excl);

    return dp[n]; 
}
int solveTab(vector<int> &nums){
    int n=nums.size();
    // step1
    vector<int> dp(n,0);
    // step2
    dp[0]=nums[0];
    // step3
    for(int i=1;i<n;i++){
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}
int solveTab2(vector<int> &nums){
     int n=nums.size();
    // step1
    vector<int> dp(n,0);
    // step2
    int prev2=0;
    int prev1=nums[0];
    // step3
    for(int i=1;i<n;i++){
        int incl=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solveMem(nums,n-1,dp);
    
    // return solveTab(nums);
    // return solveTab2(nums);
}