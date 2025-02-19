// 1143. Longest Common Subsequence

// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common
// subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none)
// deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:
// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

// Example 2:
// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.

// Example 3:
// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

class Solution {
public:
    // int solve(string text1, string text2, int n, int m){
    //     if(n==0 || m==0 ){
    //         return 0;
    //     }
    //     if(text1[n-1] == text2[m-1]){
    //         return 1 + solve(text1,text2,n-1,m-1);
    //     }
    //     else{
    //        return max(solve(text1,text2,n-1,m),solve(text1,text2,n,m-1)); 
    //     }
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
		int m = text2.length();
        
        // RECURSION
        // int ans = solve(text1, text2, n, m);
        // return ans

        // TABULATION
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i][j]=-1;
			}
		}
        for(int j=0;j<=m;j++){
		 	dp[0][j]=0;
		}

		for(int i=0;i<=n;i++){
			dp[i][0]=0;
		}
        for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
                // if character matched
				if(text1[i-1] == text2[j-1])
					dp[i][j] = 1 + dp[i-1][j-1];
                // if character not matched 
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
        return dp[n][m];
    }
};