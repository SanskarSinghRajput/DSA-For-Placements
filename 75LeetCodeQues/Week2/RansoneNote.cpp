// 383 Ransome Note
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters
// from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

// Example 1:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Map to store the count of each character in the magazine string
        unordered_map<char, int> count;

        // Count the occurrences of each character in the magazine string
        for (auto i : magazine)
            count[i]++;

        // Decrease the count of each character present in the ransomNote
        for (auto i : ransomNote)
            count[i]--;

        // Iterate through the count map
        for (auto i : count) {
            // If the count of a character in the map is negative, it means the 
            // character's occurrence in the ransomNote exceeds its occurrence in
            // the magazine, so return false
            if (i.second < 0)
                return false;
        }

        // If all characters' counts are non-negative, return true
        return true;
    }
};