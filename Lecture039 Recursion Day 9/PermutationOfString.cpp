#include <bits/stdc++.h> 
void solve(vector<int> &vec,vector<vector<int>> &ans,int index,int size){
    if(index>=size){
       ans.push_back(vec);
       return;
    }
    for(int i=index;i<size;i++){
        swap(vec[i],vec[index]);
        solve(vec,ans,index+1,size);
        // backtrack
        swap(vec[i],vec[index]);
    }
}
vector<vector<int>> permutations(vector<int> &vec, int size) {
    vector<vector<int>> ans;
    int index = 0;
    solve(vec,ans,index,size);
    return ans;
}