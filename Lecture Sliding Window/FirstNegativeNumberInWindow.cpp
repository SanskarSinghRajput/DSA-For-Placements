// First negative integer in every window of size k
// Given an array A[] of size N and a positive integer K, find the first negative integer for each and 
// every window(contiguous subarray) of size K.

// Input : N = 5 A[] = {-8, 2, 3, -6, 10} K = 2
// Output : -8 0 -6 -6
// Explanation: First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

#include <bits/stdc++.h>
using namespace std;

// Approach 1 using Sliding Window Technique
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K){
    int i=0, j=0;
    list<long long> l;
    vector<long long> ans;
    
    while(j<N){
        // calculation 
        if(A[j] < 0)
            l.push_back(A[j]);
        
        // until we get 'K' elements from front side
        if(j-i+1 < K)
            j++;
        
        else if(j-i+1 == K){
          if(l.size()==0)
              ans.push_back(0);
          
          else{
              ans.push_back(l.front()); 
               if(A[i]==l.front())
               l.pop_front();    
          }
          i++;
          j++;
        }
    }
    return ans;
}

// Approach 2 Using Queue in sliding window technique
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        deque<long long int> dq;
        vector<long long> ans;

        //process first window
        for(int i=0; i<K; i++) {
            if(A[i] < 0)
               dq.push_back(i);
        }
         
        //push ans for FIRST window
        if(dq.size() > 0) 
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
         
        //now process for remaining windows
        for(int i = K; i<N; i++) {
            //first pop out of window element   
            if(!dq.empty() && (i - dq.front())>=K ) 
                dq.pop_front();
             
            //then push current element
            if(A[i] < 0)
               dq.push_back(i);
            
           // put in ans
           if(dq.size() > 0)
                ans.push_back(A[dq.front()]);
           else
               ans.push_back(0);
        }
        return ans;
 }

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

