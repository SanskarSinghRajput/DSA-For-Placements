// 125 Valid Palindrome

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if a character is a valid alphabet (a-z or A-Z)
    bool isvalid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            return true;
        else
            return false;
    }

    // Function to check if a string is a palindrome
    bool checkPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;
        // Loop until the start pointer is less than or equal to the end pointer
        while (st <= end) {
            if(s[st] == s[end]) {
                st++;
                end--;
            }
            // If characters don't match, it's not a palindrome
            else
                return false; 
        }
        // If the loop completes without returning false, it's a palindrome
        return true;
    }

    // Function to check if a string is a palindrome considering only alphanumeric characters
    bool isPalindrome(string s) {
        string temp = "";
        // Remove unnecessary characters such as spaces, commas, colons, etc.
        for(int i = 0; i < s.length(); i++) {
            // Add valid characters to the temporary string
            if(isvalid(s[i]))
                temp.push_back(s[i]); 
        }
        // Convert all characters to lowercase
        for(int i = 0; i < temp.length(); i++) {
            // Skip lowercase characters
            if(temp[i] >= 'a' && temp[i] <= 'z')
                continue; 

            // Convert uppercase characters to lowercase
            else
                temp[i] = temp[i] - 'A' + 'a';
        }
        // Check if the modified string is a palindrome
        return checkPalindrome(temp);
    }
};

int main() {
    Solution sol;

    // Example usage
    string input = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(input);
    
    if(result)
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
