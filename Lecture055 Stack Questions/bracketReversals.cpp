// Minimum Bracket Reversals Minimum to make String Valid
// Sample Input 1:
// {{{}
// {{}{}}
// Sample Output 1:
// 1
// 0

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost of balancing an expression
int findMinimumCost(string str) {
    // Odd length expressions cannot be balanced
    if(str.length() % 2 == 1)
        return -1;

    stack<char> s;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch == '{'){
            // Push opening braces onto the stack
            s.push(ch);
        } 
        else{
            // If the current character is a closing brace
            if(!s.empty() && s.top() == '{') {
                // If an opening brace is found, pop it (as it balances the closing brace)
                s.pop();
            } 
            else{
                // If no matching opening brace is found, push the closing brace onto the stack
                s.push(ch);
            }
        }
    }

    // Count the unbalanced braces remaining in the stack
    int unbalancedOpenBracket = 0, unbalancedCloseBracket= 0;
    while(!s.empty()) {
        if(s.top() == '{') 
            unbalancedCloseBracket++; // Count of unbalanced closing braces
        else
            unbalancedOpenBracket++; // Count of unbalanced opening braces
        s.pop();
    }

    // Calculate the minimum cost of balancing the expression
    int ans = (unbalancedOpenBracket + 1) / 2 + (unbalancedCloseBracket + 1) / 2;
    return ans;
}
