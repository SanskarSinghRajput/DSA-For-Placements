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
    // Approach 1: Sorting
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // Approach 2: Hash Table
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for(auto x : s){
            count[x]++;
        }
        // Decrement the frequency of characters in string t
        for(auto x : t){
            count[x]--;
        }
        // Check if any character has non-zero frequency
        for(auto x : count) {
            if(x.second != 0) {
                return false;
            }
        }  
        return true;
    }

    // Approach 3: Hash Table (Using Array)
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        
        // Count the frequency of characters in string s
        for(char x : s){
            count[x - 'a']++;
        }
        // Decrement the frequency of characters in string t
        for(char x : t){
            count[x - 'a']--;
        }
        // Check if any character has non-zero frequency
        for(int val : count){
            if(val != 0)
                return false;
        }  
        return true;
    }

    // Approach 4: Using Array
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
