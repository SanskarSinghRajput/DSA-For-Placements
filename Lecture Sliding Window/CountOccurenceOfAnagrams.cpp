#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int search(string pat, string txt){
        int i = 0, j = 0;          // Pointers for iterating through txt
        int N = txt.length();      // Length of txt
        int K = pat.length();      // Length of pat
        unordered_map<int, int> m; // Map to store frequency of characters in pat
        int ans = 0;               // Variable to store the count of occurrences of pat in txt

        // Count the frequency of characters in pat
        for (int i = 0; i < K; i++)
            m[pat[i]]++;

        int count = m.size(); // Count of distinct characters in pat

        // Loop through txt
        while (j < N){
            // If the current character in txt is present in pat
            if (m.find(txt[j]) != m.end()){
                m[txt[j]]--; // Decrement the frequency of the character
                if (m[txt[j]] == 0)
                    count--; // Decrement the count of distinct characters if their frequency becomes 0
            }

            // If the window size is less than the length of pat
            if (j - i + 1 < K)
                j++; // Expand the window

            // If the window size equals the length of pat
            else if (j - i + 1 == K){
                // Check if all characters of pat are found in the current window
                if (count == 0)
                    ans++; // Increment the count of occurrences

                // If the current character in txt is present in pat
                if (m.find(txt[i]) != m.end())
                {
                    m[txt[i]]++; // Restore the frequency of the character
                    if (m[txt[i]] == 1)
                        count++; // Increment the count of distinct characters
                }
                // Slide the window by incrementing i and j
                i++;
                j++;
            }
        }
        return ans; // Return the count of occurrences of pat in txt
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
