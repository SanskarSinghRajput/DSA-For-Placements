// 409 Longest Palindrome
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the length of the longest palindrome that can be built with the characters in the string
    int longestPalindrome(string s) {
        unordered_map<char, int> mp; // Map to store the frequency of characters in the string
        
        // Count the frequency of each character in the string
        for (auto i : s)
            mp[i]++;
        
        // Variable to store the length of the longest palindrome
        int ans = 0;
        // Flag to indicate if an odd-frequency character is present
        bool isOddPresent = false;
        
        // Iterate through the characters and their frequencies in the map
        for (auto i : mp) {
            if (i.second % 2 == 0){
                // If the frequency is even, add it directly to the palindrome length
                ans += i.second;
            }
            else {
                // If the frequency is odd, add (frequency - 1) to the palindrome length
                ans += i.second - 1; 
                // Set the flag to true indicating that an odd-frequency character is present
                isOddPresent = true; 
            }
        }
        
        if(isOddPresent){
            // If an odd-frequency character is present, add 1 to the palindrome length
            ans += 1;
        }
        return ans; // Return the length of the longest palindrome
    }
};
