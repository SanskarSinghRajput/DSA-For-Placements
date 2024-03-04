// Reverse String
#include<bits/stdc++.h>
using namespace std;

int main () {
    string str = "babbar";

    stack<char> s;
    // push each character into stack
    for (int i = 0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    
    while(!s.empty()) {
        char ch = s.top();
        // push top of stack
        ans.push_back(ch);

        s.pop();
    }
    // answer contains reverse order of characters in the given string
    cout << "answer is: "<< ans << endl;

    return 0;
}