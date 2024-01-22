#include <bits/stdc++.h>
using namespace std;

// Given two integer array A and B of size N each. A sum combination is made by adding one element from array
// A and another element of array B. Return the maximum K valid sum combinations from all the possible sum 
// combinations.
// Note : Output array must be sorted in non-increasing order.

// Example 1
// Input:
// N = 4
// K = 3
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// Output: {10, 9, 9}
// Explanation: 
// 10 -> (A : 4) + (B : 6)
// 9 -> (A : 4) + (B : 5)
// 9 -> (A : 3) + (B : 6)

// Example 2
// For Input: 
// 4 3
// 1 4 2 3
// 2 5 1 6
// Your Output: 
// 10 9 9
// Expected Output: 
// 10 9 9

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Sort the input arrays in descending order.
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<int, vector<int>,greater<int>> pq;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int sum = A[i] + B[j];
                if(pq.size() < K || sum > pq.top()){
                  pq.push(sum);
                  // If the size exceeds K, pop the smallest element.
                  if(pq.size() > K){
                      pq.pop();
                  }
                }
                else{
                    // Since the arrays are sorted in descending order, if A[i]+B[j] <= pq.top(),
                    // further elements in B won't yield a larger sum, so break the inner loop.
                    break;
                }
            }
        }
        vector<int> ans;
        // Transfer elements from the priority queue to the result vector.
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        // Reverse the result vector to get the elements in descending order.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
