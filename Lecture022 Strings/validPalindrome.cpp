// 125 ValidPalindrome
#include <bits/stdc++.h>
using namespace std;

// Check Palindrome 2 Approaches
    //----------Approach 1----------
    // Step1- Reverse the String and Store it into a new String
    // Step2- Then Compare both strings if Str1 == Str2 using strcmp(str1,str2) == 0 is Palindrome
    // else not Palindrome

    //----------Approach 2----------
    // Step1- Initialize two variable s=0 and e=str.length()-1
    // Step2- Then run loop while(s<=e) check in every Iteration
    // Step3- If(a[s] = a[e]) s++, e-- and check further characters
    // Step4- Else return 0 means not a Palindrome
    // Step5- When loop finishes return 1 means is Palindrome

class Solution{
private:
    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            return 1;
        return 0;
    }

    char toLowerCase(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(string a){
        int s = 0;
        int e = a.length() - 1;

        while(s <= e){
            if (a[s] != a[e])
                return 0;
            else
                s++;
                e--;
        }
        return 1;
    }

public:
    // Optimized Approuach
    // Function to check if a string is a palindrome 
    bool isPalindrome(string s) {
        string temp = "";
        // Remove unnecessary characters such as spaces, commas, colons, etc.
        for(int i = 0; i < s.length(); i++) {
            // Add valid characters to the temporary string
            if(valid(s[i]))
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

    bool isPalindrome(string s){
        // faltu character hatado
        string temp = "";
        for(int j = 0; j < s.length(); j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        // lowercase me kardo
        for (int j = 0; j < temp.length(); j++){
            temp[j] = toLowerCase(temp[j]);
        }
        // check palindrome
        return checkPalindrome(temp);
    }
};