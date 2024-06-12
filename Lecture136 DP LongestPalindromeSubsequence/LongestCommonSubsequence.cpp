class Solution {
public:
    // Tabulation
    int solveTab(string a, string b){
        vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1,0));

        for(int i = a.length()-1; i >= 0; i--){
           for(int j = b.length()-1; j >= 0; j--){
              int ans = 0;
              if(a[i] == b[j])
                ans = 1 + dp[i+1][j+1];
              else
                ans = 0 + max(dp[i+1][j], dp[i][j+1]);
              dp[i][j] = ans;
           }
        }
        return dp[0][0];
    }

    // Tabulation + SO
    int solveTabSO(string a, string b){
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length()-1; i >= 0; i--){
           for(int j = b.length()-1; j >= 0; j--){
              int ans = 0;
              if(a[i] == b[j])
                ans = 1 + next[j+1];
              else
                ans = 0 + max(next[j], curr[j+1]);
              curr[j] = ans;
           }
           next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string strRev = s;
        reverse(strRev.begin(), strRev.end());

        int ans = solveTabSO(s, strRev);
        return ans;
    }
};