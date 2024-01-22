#include <bits/stdc++.h>
//Method 1
void solve(string &str,vector<string> &ans,int index){
	if(index>=str.size()){
        ans.push_back(str);
    }
	unordered_set<char>m; 
	//for unique Permutation of the string
    for(int j=index;j<str.size();j++){
		// In if it comapres m.find(str[j]) result with m.end()
		// if str[j] is present then m.find(str[j]) is not equal to m.end()
		// so continue executes
		if(m.find(str[j]) != m.end())
		   continue;
		m.insert(str[j]);
        swap(str[index],str[j]);
        solve(str,ans,index+1);
        //backtrack
        swap(str[index],str[j]);
    }
}
vector<string> uniquePrem(string& str) {
	vector<string> ans;
	int index = 0;
	solve(str,ans,index);
	sort(ans.begin(),ans.end());
	return ans;
}


// Method 2
void solve(vector<int> &arr,set<vector<int>> &ans,int index, int n){
	if(index>=n){
		ans.insert(arr);
		return;
	}
	for(int i=index;i<n;i++){
		swap(arr[index],arr[i]);
		solve(arr,ans,index+1,n);
		// backtracking
		swap(arr[index],arr[i]);
	}
}
vector<vector<int> > uniquePermutations(vector<int> &arr, int n) {
	set<vector<int>> ans;
	int index = 0;
	solve(arr,ans,index,n);

	vector<vector<int>> res(ans.begin(),ans.end());
	return res;
}