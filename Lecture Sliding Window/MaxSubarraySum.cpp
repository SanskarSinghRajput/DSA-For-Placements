// Maximum subarray Sum
// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
// NOTE*: A subarray is a contiguous part of any given array.

// Example 1:
// Input:
// N = 4, K = 2
// Arr = [100, 200, 300, 400]
// Output: 700
// Explanation: Arr3  + Arr4 = 700,which is maximum.

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    // Brute Force Approach
    long maximumSumSubarray(int K, vector<int> &Arr, int N) {
      long maxi = INT_MIN;
      long sum = 0;

      for(int i = 0; i < N; i++) {
         for(int j = i; j < i + K; j++) {
            sum += Arr[j];
         }
        maxi = max(maxi, sum);
        sum = 0;
      }
      return maxi;
    }

    // Optimized Apporach 1 using Sliding Window
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
       int i=0, j=0;
       long maxi=INT_MIN;
       long sum=0;
    
        while(j<N){
           // calculation 
           sum=sum+Arr[j];
           // until noy hit
           if(j-i+1 < K){
               j++;
           }
           else if(j-i+1 == K){
               // answer nikalo 
               maxi=max(maxi,sum);
               sum=sum-Arr[i];
               i++;
               j++;
           }
        }
        return maxi;
    }

    // Optimized Apporach 2 using Sliding Window
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long max_sum = LONG_MIN;
        long long sum = 0;
        // calculate sum of first k elements in array
        for(int i=0;i<K;i++){
            sum += Arr[i];
        }
        // store max_sum value
        max_sum = sum;
        for(int i=K;i<N;i++){
            // subtract previous element and add current element to get the new sum
            sum += Arr[i];
            sum -= Arr[i-K];
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 