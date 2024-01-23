// Maximum Occuring Character

// Given a string str of lowercase alphabets. The task is to find the maximum occurring character in
// the string str. If more than one character occurs the maximum number of time then print the 
// lexicographically smaller character.

// Example 1:
// Input:
// str = testsample
// Output: e
// Explanation: e is the character which
// is having the highest frequency.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str){
        map<char,int> m;
        char ans;
        int maxi = INT_MIN;
        for(int i=0;i<str.length();i++)
            m[str[i]]++;
            
        for(auto it:m){
            if(maxi < it.second){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }

};

int main(){   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}