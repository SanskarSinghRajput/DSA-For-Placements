// Reverse Words in a String III

// Given a string, you need to reverse the order of characters in each word within a sentence while still
// preserving whitespace and initial word order.

// Example 1:
// Input:
//  "Let's take LeetCode contest"

// Output:
//  "s'teL ekat edoCteeL tsetnoc"

//-----------Approach-----------
// Step-1 Iterate through the string character by character.
// Step-2 Identify the start and end indices of each word.
// Step-3 Reverse the characters within each word.
// Step-4 Reconstruct the modified string.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to reverse characters in a given range [s, t] of a character array
    void reverse(char chs[], int s, int t) {
        while (s < t) {
            swap(chs[s],chs[t]);
            s++;
            t--;
        }
    }

    // Main function to reverse the order of characters in each word in a sentence
    string reverseWords(string s) {
        int i = 0, j = 0;
        int n = s.length();

        // Convert string to character array
        char* chs = new char[n + 1];
        strcpy(chs, s.c_str());

        // Iterate through the string to reverse characters within each word
        while (i < n && j < n) {
            // Skip leading spaces to find the start of a word
            while (i < n && chs[i] == ' ') {
                i++;
            }
            j = i; // j points to the start of the current word
            // Find the end of the current word
            while (j < n && chs[j] != ' ') {
                j++;
            }
            // Reverse the characters within the current word
            reverse(chs, i, j - 1);
            i = j; // Move i to the next word
        }

        // Create a string from the modified character array
        string result(chs);

        // Free the dynamically allocated memory
        delete[] chs;

        return result;
    }
};
