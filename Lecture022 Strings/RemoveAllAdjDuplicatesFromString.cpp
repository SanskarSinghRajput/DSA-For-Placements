// Remove All Adjacent Duplicates In String

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of 
// choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the
// answer is unique.

// Example 1:
// Input: s = "abbaca"
// Output: "ca"

// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is 
// the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is 
// possible, so the final string is "ca".

//-------------------Approach---------------------
// Step 1: Initialize a stack to keep track of characters
// Step 2: Iterate through each character in the input string
// Step 3: Check if the stack is not empty and the top of the stack is equal to the current character
        // If yes, pop the top element from the stack (removing the duplicate)
        // If no, push the current character onto the stack
// Step 4: Build the result string from the stack
// Append each character from the top of the stack to the result string
// Step 5: Reverse the result string to get the correct order
// Step 6: Return the final result after removing duplicates

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // Initialize a stack to keep track of characters
        stack<char> st;

        // Iterate through each character in the input string
        for (auto ch : s) {
            // Check if the stack is not empty and the top of the stack is equal to the current character
            if (!st.empty() && st.top() == ch) {
                // If yes, pop the top element from the stack (removing the duplicate)
                st.pop();
            } else {
                // If no, push the current character onto the stack
                st.push(ch);
            }
        }

        // Build the result string from the stack
        string ans;
        while (!st.empty()) {
            // Append each character from the top of the stack to the result string
            ans += st.top();
            st.pop(); // Pop the character after appending it
        }

        // Reverse the result string to get the correct order
        reverse(ans.begin(), ans.end());

        // Return the final result after removing duplicates
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "abbaca";

    // Test the function
    string result = solution.removeDuplicates(s);

    // Display the result
    cout << "Input: " << s << endl;
    cout << "Output: " << result << endl;

    return 0;
}
