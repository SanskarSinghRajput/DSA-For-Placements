// 20 Valid Parenthesis
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if the given string contains valid parentheses
    bool isValid(string s) {
        stack<char> st; // Stack to store opening parentheses

        // Loop through each character in the string
        for(int i = 0; i < s.length(); i++) {
            // If the character is an opening parenthesis, push it onto the stack
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                // If the character is a closing parenthesis
                if(!st.empty() && ((st.top() == '(' && s[i] == ')') || 
                                   (st.top() == '{' && s[i] == '}') || 
                                   (st.top() == '[' && s[i] == ']'))) {
                    // If the stack is not empty and the top of the stack matches the current closing parenthesis,
                    // pop from the stack
                    st.pop();
                } 
                else{
                    // If the stack is empty or the top of the stack does not match the current closing
                    // parenthesis,return false
                    return false;
                }
            }
        }

        // If the stack is empty after processing all characters, return true; otherwise, return false
        return st.empty();
    }
};

int main() {
    Solution sol;

    // Example usage
    string s = "{[]}";
    bool result = sol.isValid(s);
    cout<< "Is the string valid? " << (result ? "Yes" : "No") << endl;

    return 0;
}
