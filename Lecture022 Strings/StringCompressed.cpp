// String Compression

// Given an array of characters chars, compress it using the following algorithm:
// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.

// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compress a vector of characters
    int compress(vector<char>& chars) {
        int i = 0;          // i is the pointer to the current character
        int ansIndex = 0;   // ansIndex is the pointer to the position in the result array
        int n = chars.size(); // n is the size of the input vector

        // Iterate through the vector of characters
        while (i < n) {
            int j = i + 1;

            // Find the length of the consecutive sequence of identical characters
            while (j < n && chars[i] == chars[j]) {
                j++;
            }
            //yaha kab aaoge jab
            //ya to poora vector traverse kar dia
            //ya fir new/different character encounter kia h

            // Store the character at ansIndex (oldChar)
            chars[ansIndex++] = chars[i];

            int count = j - i; // Count of consecutive identical characters

            if (count > 1) {
                // Convert the count into a string and store each digit in the result array
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansIndex++] = ch;
                }
            }

            i = j; // Move the pointer to the next different character
        }

        return ansIndex; // Return the length of the compressed array
    }
};

int main() {
    Solution solution;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    // Test the function
    int resultLength = solution.compress(chars);

    // Display the result vector and its length
    cout << "Compressed Vector: ";
    for (int i = 0; i < resultLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    cout << "Length of Compressed Vector: " << resultLength << endl;

    return 0;
}
