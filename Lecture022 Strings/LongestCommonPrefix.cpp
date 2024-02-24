// Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the longest common prefix among an array of strings
    string longestCommonPrefix(vector<string>& strs) {
      // Sort the array of strings
      sort(strs.begin(), strs.end());
    
      // Get the first and last string after sorting
      int size = strs.size();
      string firstStr = strs[0];
      string lastStr = strs[size - 1];
    
      // Initialize an empty string to store the longest common prefix
      string ans = "";
    
      // Iterate through characters of the first string
      for(int i = 0; i < firstStr.size(); i++) {
        // If the character at the same position in the first and last strings is the same,
        // add it to the longest common prefix
        if(firstStr[i] == lastStr[i])
           ans += firstStr[i];
        else{
           // If characters are different, break the loop
           break;
        }
      }
      // Return the longest common prefix
      return ans;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<string> input = {"flower", "flow", "flight"};
    string output = solution.longestCommonPrefix(input);

    // Output the result
    cout << "Longest Common Prefix: " << output << endl;

    return 0;
}
