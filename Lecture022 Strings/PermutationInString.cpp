// Permutation in String

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to check if two arrays are equal
    bool checkEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    // Function to check if s1 is a permutation of any substring of s2
    bool checkInclusion(string s1, string s2) {
        // Character count array for s1
        int count1[26] = {0};

        // Count occurrences of each character in s1
        for (int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // Traverse s2 string in a window of size s1 length and compare
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};

        // Running for the first window
        while (i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // Check if the first window is a permutation of s1
        if (checkEqual(count1, count2))
            return true;

        // Move the window forward
        while (i < s2.length()) {
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;

            i++;

            // Check if the current window is a permutation of s1
            if (checkEqual(count1, count2))
                return true;
        }

        // If no permutation is found
        return false;
    }
};

int main() {
    Solution solution;
    string s1 = "abc";
    string s2 = "eidbaooo";

    // Test the function
    bool result = solution.checkInclusion(s1, s2);

    // Display the result
    cout << (result ? "True" : "False") << endl;

    return 0;
}
