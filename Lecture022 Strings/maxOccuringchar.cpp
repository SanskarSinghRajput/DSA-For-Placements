//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
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

//{ Driver Code Starts.

int main()
{
   
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
// } Driver Code Ends