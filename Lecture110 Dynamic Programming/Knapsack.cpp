#include <bits/stdc++.h>
int solve(vector<int> &weight,vector<int> &value,int index,int Capacity) {
	//base case
	//if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index==0){
		if(weight[0]<=Capacity)
			return value[0];
		else 
		    return 0;
	}
	int include = 0;
	if(weight[index]<=Capacity)
		include=value[index]+solve(weight,value,index-1,Capacity-weight[index]);
    
	int exclude=0+solve(weight,value,index-1,Capacity);
	 
	int ans=max(include,exclude);
	return ans;
}

int solveMem(vector<int> &weight,vector<int> &value,int index,int Capacity,vector<vector<int>> &dp){
	//base case
	//if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index==0){
	  if(weight[0]<=Capacity)
	  	return value[0];
	  else 
	    return 0;
	}
	if(dp[index][Capacity]!=-1)
	   return dp[index][Capacity];

	int include = 0;
	if(weight[index]<=Capacity)
		include=value[index]+solveMem(weight,value,index-1,Capacity-weight[index],dp);
    
	int exclude=0+solveMem(weight,value,index-1,Capacity,dp);
	 
	dp[index][Capacity]=max(include,exclude);
	return dp[index][Capacity];
}

int solveTab(vector<int> &weight,vector<int> &value,int n,int Capacity){
	// step1:
	vector<vector<int>> dp(n,vector<int>(Capacity+1,0));

	//step2: analyse base case
	for(int w=weight[0];w<=Capacity;w++){
	   if(weight[0]<=Capacity)
	  	  dp[0][w]=value[0];
	   else 
	      dp[0][w]= 0;
	}
    // step3: take care of remaining recursive calls
	for(int index=1;index<n;index++){
		for(int w=0;w<=Capacity;w++){
           int include = 0;

	       if(weight[index]<=w)
	       	  include=value[index]+dp[index-1][w-weight[index]];
    
	       int exclude=0+dp[index-1][w];
	 
	       dp[index][w]=max(include,exclude);
		}
	}
	return dp[n-1][Capacity];
}

int solveTab2(vector<int> &weight,vector<int> &value,int n,int Capacity){
	// step1:
	vector<int> prev(Capacity+1,0);
	vector<int> curr(Capacity+1,0);

	//step2: analyse base case
	for(int w=weight[0];w<=Capacity;w++){
	   if(weight[0]<=Capacity)
	  	  prev[w]=value[0];
	   else 
	      prev[w]= 0;
	}
    // step3: take care of remaining recursive calls
	for(int index=1;index<n;index++){
		for(int w=0;w<=Capacity;w++){
           int include = 0;

	       if(weight[index]<=w)
	       	  include=value[index]+prev[w-weight[index]];
    
	       int exclude=0+prev[w];
	 
	       curr[w]=max(include,exclude);
		}
		prev=curr;
	}
	return prev[Capacity];
}
int solveTab3(vector<int> &weight,vector<int> &value,int n,int Capacity){
	// step1:
	vector<int> prev(Capacity+1,0);
	vector<int> curr(Capacity+1,0);

	//step2: analyse base case
	for(int w=weight[0];w<=Capacity;w++){
	   if(weight[0]<=Capacity)
	  	  prev[w]=value[0];
	   else 
	      prev[w]= 0;
	}
    // step3: take care of remaining recursive calls
	for(int index=1;index<n;index++){
		for(int w=Capacity;w>0;w--){
           int include = 0;

	       if(weight[index]<=w)
	       	  include=value[index]+prev[w-weight[index]];
    
	       int exclude=0+prev[w];
	 
	       curr[w]=max(include,exclude);
		}
		prev=curr;
	}
	return prev[Capacity];
}

int knapsack(vector<int> weight,vector<int> value,int n,int maxWeight) 
{
	// return solve(weight,value,n-1,maxWeight);

	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	// return solveMem(weight,value,n-1,maxWeight,dp);

	// return solveTab(weight,value,n,maxWeight);

	// return solveTab2(weight,value,n,maxWeight);
	
	return solveTab3(weight,value,n,maxWeight);
}