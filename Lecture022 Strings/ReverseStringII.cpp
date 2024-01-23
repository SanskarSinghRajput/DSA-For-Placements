// Reverse String II

// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from
// the start of the string.
// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater
// than or equal to k characters, then reverse the first k characters and leave the other as original.

// Example 1:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"

// Example 2:
// Input: s = "abcd", k = 2
// Output: "bacd"

//------Approach---------

// 1 Initialize an index i to traverse the string.
// 2 Iterate through the string in steps of 2k.
// 3 For each group of 2k characters, reverse the first k characters if there are at least k characters remaining.
// 4 Move to the next group and repeat until the end of the string.


//-----------DRY RUN OF THIS APPROACH----------------

// Initial State:
// s = "abcdefg"
// k = 2
// n = 7

// Iteration 1:
// Initial index i = 0
// Calculate end index: end = min(0 + 2 - 1, 7 - 1) = min(1, 6) = 1
// Reverse the first k = 2 characters: "ba"cdefg
// Update index i = 4 (move to the next group)

// Iteration 2:
// Calculate end index: end = min(4 + 2 - 1, 7 - 1) = min(5, 6) = 5
// Reverse the first k = 2 characters: "bacdfe"g
// Update index i = 8 (move to the next group)

// Result:
// The final modified string is "bacdfeg".
// So, the output of the code with the given input (s = "abcdefg", k = 2) is "bacdfeg"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int i = 0;

        while (i < n) {
            // Calculate the end index for the current group of 2k characters
            int end = min(i + k - 1, n - 1);

            // Reverse the first k characters in the current group
            reverse(s.begin() + i, s.begin() + end + 1);

            // Move to the next group of 2k characters
            i += 2 * k;
        }

        return s;
    }
};

int main() {
    Solution solution;
    string s = "abcdefg";
    int k = 2;
    string result = solution.reverseStr(s, k);
    cout << result << endl;
    return 0;
}
