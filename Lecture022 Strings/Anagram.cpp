// Anagram
// Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings
// are an anagram of each other or not. An anagram of a string is another string that contains the same characters,
// only the order of characters can be different.

// Input:a = geeksforgeeks, b = forgeeksgeeks
// Output: YES
// Explanation: Both the string have same characters with same frequency. So, both are anagrams.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        // Step1:Initialise vector to store count of each character in the string 
        vector<int> count1(26);
        vector<int> count2(26);
        
        // Step 2:store the frequency of each character of string a
        for(int i=0; i<a.length(); i++){
            count1[a[i]-'a']++;
        }
        
        // Step 3:store the frequency of each character of string b
        for(int i=0; i<b.length(); i++){
            count2[b[i]-'a']++;
        }
        
        // if both the vector are same then it will return true else false;
        return count1==count2;
    }
};

int main() { 
    int t;
    cin >> t;
    while(t--){
        string c, d;
        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
