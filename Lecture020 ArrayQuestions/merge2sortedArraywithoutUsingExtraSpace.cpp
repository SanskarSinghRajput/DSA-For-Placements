#include <bits/stdc++.h> 
using namespace std; 
// Brute Force approach with using extra space is take third array of size n+m, then compare element of both
// arrays and add the smallest element in third array and repeat the process until all element of both arrays
// are placed in third array

class Solution{
    public:
        // Striver's
        // Optimize Approach 1
        //Function to merge two sorted arrays.
        void merge(long long arr1[], long long arr2[], int n, int m){ 
            int left = n-1;
            int right = 0;
            
            while(left>=0 && right<m){
                if(arr1[left] >= arr2[right])
                  swap(arr1[left--],arr2[right++]);
                  
                else if(arr1[left] < arr2[right])
                  break;
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 

        // Striver's
        // Optimize Approach 2
        // Using shell sort algorithim solve this
        void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
            if(arr1[ind1] > arr2[ind2])
              swap(arr1[ind1],arr2[ind2]);
        }
        void merge2(long long arr1[], long long arr2[], int n, int m){ 
            int len = n+m;
            // gap contains ceiling value of len/2 so we add (len%2) if len is odd.
            int gap = (len/2) + (len%2);
            while(gap>0){
                int left = 0;
                int right = left + gap;
                while(right<len){
                    if(left<n && right>=n)
                        swapIfGreater(arr1,arr2,left,right-n);
                    
                    else if(left>=n)
                        swapIfGreater(arr2,arr2,left-n,right-n);
                    
                    else
                        swapIfGreater(arr1,arr1,left,right);
                    
                    left++, right++;
                }
                if(gap==1)  break;
                
                gap = (gap/2) + (gap%2);
            }
        } 
};

int main(){ 
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++)
	        cin >> arr1[i];
	    
	    for(int i = 0;i<m;i++)
	        cin >> arr2[i];
	    
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}
	return 0; 
} 
