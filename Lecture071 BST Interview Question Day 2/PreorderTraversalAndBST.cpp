//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // For larger inputs we will use the same approach in iterative form
    
    int canRepresentBST(int arr[] , int N){
        stack<pair<int,int>> st;
        int i = 0;
        st.push({INT_MIN , INT_MAX});
        while(!st.empty() && i < N){
            pair<int,int> top = st.top();
            st.pop();
            
            if(arr[i] >= top.first && arr[i]  <= top.second){
                int data = arr[i];
                i++;
                st.push({data , top.second});
                st.push({top.first , data});
            }
        }
        
        if(i==N)
          return 1;
          
        return 0;
    }
    
    // The below approach works for small inputs but for larger inputs it gives segmentation fault
  
    // void solve(int arr[], int N,int mini,int maxi,int &i){
    //     if(i >= N)
    //       return ;
          
    //     if(arr[i] < mini || arr[i] > maxi)
    //       return ;
          
    //     int data = arr[i];
    //     i++;
    //     // Left
    //     solve(arr,N,mini,data,i);
    //     // Right
    //     solve(arr,N,data,maxi,i);
    // }
    // int canRepresentBST(int arr[], int N){
    //     int mini = INT_MIN;
    //     int maxi = INT_MAX;
    //     int i = 0;
    //     solve(arr,N,mini,maxi,i);
        
    //     if(i==N)
    //       return 1;
          
    //     return 0;
    // }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends