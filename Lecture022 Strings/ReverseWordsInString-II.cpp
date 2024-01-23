// Reverse Words in a String II

// Given an input string, reverse the string word by word.

// Example:
// Input:  
// ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
// ​
// Output: 
// ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

//------------Approach-------------------------
// Step-1 Reverse the Entire String:
// Step-2 Reverse Each Word:

// Time Complexity: O(n)
// Linear time complexity as we traverse the string once.
// Space Complexity: O(1)
// Constant space, as we perform the reversal in-place without using additional space.

//--------------DRY RUN OF CODE-----------------
// Initial State:
// input vector is {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'}

// Step 1: Reverse the Entire String
// input after the first reverse becomes {'e','u','l','b',' ','s','i',' ','y','k','s',' ','e','h','t'}

// Step 2: Reverse Each Word
// Start iterating through the reversed vector:
// For the word "eulb", reverse it: {'b','l','u','e',' ','s','i',' ','y','k','s',' ','e','h','t'}
// For the word "si", reverse it:   {'b','l','u','e',' ','i','s',' ','y','k','s',' ','e','h','t'}
// For the word "yks", reverse it:  {'b','l','u','e',' ','i','s',' ','s','k','y',' ','e','h','t'}
// For the word "eht", reverse it:  {'b','l','u','e',' ','i','s',' ','s','k','y',' ','t','h','e'}

// Result:
// The final reversed vector is {'b','l','u','e',,' ','i','s',' ','s','k','y',' ','t','h','e'}.
// So, the code successfully reverses the words in the string in-place.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(),s.end());
        
        // Step 2: Reverse each word
        int start = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
           if(s[i] == ' '){
              reverse(s.begin() + start, s.begin() + i);
              start = i + 1;
           }
        }
        
        // Reverse the last word (or the only word if there's no space at the end)
        reverse(s.begin() + start, s.end());
    }
};

int main() {
    Solution solution;

    // Example input
    vector<char> input = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};

    // Apply the reverseWords function
    solution.reverseWords(input);

    // Output the reversed string
    for (char c : input) {
        cout << c << " ";
    }

    return 0;
}
