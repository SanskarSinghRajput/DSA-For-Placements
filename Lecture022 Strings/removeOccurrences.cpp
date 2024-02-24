// 1910. Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the
// substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// Example 1:
// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"

// Explanation:
// s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Iterate until there are no more occurrences of 'part' in the string 's'
        while (s.length() != 0 && s.find(part) != string::npos) {
            // Find the position of the first occurrence of 'part' in 's'
            size_t pos = s.find(part);
            
            // Erase the found occurrence of 'part' from 's'
            s.erase(pos, part.length());
        }

        // Return the modified string 's' after removing all occurrences of 'part'
        return s;
    }

    string removeOccurrences2(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};

int main() {
    // Example usage:
    Solution solution;

    // Input string
    string inputString = "leetcodeleet";
    
    // Part to be removed
    string partToRemove = "leet";

    // Call the function to remove occurrences
    string result = solution.removeOccurrences(inputString, partToRemove);

    // Display the result
    cout << "Result: " << result << endl;

    return 0;
}