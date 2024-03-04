// Find redundant brackets in a given expression
#include<bits/stdc++.h>
using namespace std;

// Function to find redundant brackets in a given expression
bool findRedundantBrackets(string &s) {
    stack<char> st; // Stack to store operators and opening parentheses

    // Traverse through the given expression
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i]; // Current character
        
        // If the current character is an operator or an opening parenthesis, push it onto the stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            // If the current character is a closing parenthesis
            if (ch == ')') {
                bool isRedundant = true; // Flag to track if the closing parenthesis is redundant

                // Pop operators until an opening parenthesis is encountered
                while (st.top() != '(') {
                    char top = st.top();
                    
                    // If an operator is encountered within the parentheses, the parentheses are not redundant
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop(); // pop top of stack
                }
                
                st.pop(); // Pop the opening parenthesis
                
                // If the parentheses are redundant, return true
                if (isRedundant)
                    return true;
            }
        }
    }
    return false; // No redundant brackets found
}

