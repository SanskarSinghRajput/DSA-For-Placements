// Non Repeating Character
// Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character
// in S. If there is no non-repeating character, return '$'.

// Input:
// S = hello
// Output: h
// Explanation: In the given string, the first character which is non-repeating
// is h, as it appears first and there is no other 'h' in the string.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S){
       // Step1:vector to store the count of character 
       vector<int> count(26);
       
       // Step2:Store the count of each character  
       for(int i=0;i<S.length();i++){
           count[S[i]-'a']++;
       }
       
       // Step 3:har char ko uthao ar check kro ki kya uska count 1 hai 
       // agar ho toh us character ko return kr do 
       for(int i=0;i<S.length();i++){
           if(count[S[i]-'a'] == 1)
             return S[i];
       }
       
       return '$';
    }

};

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
