// 354 Russian Doll Envelopes

class Solution {
public:
    // Using Dp with binary search
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if(size == 0)
          return 0;

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> dp;
        for(int i=0; i<size; i++){
            auto it = lower_bound(dp.begin(), dp.end(),envelopes[i][1]);

            if(it == dp.end())
              dp.push_back(envelopes[i][1]);
            else
              *it = envelopes[i][1];
        }
        return dp.size();
    }
};