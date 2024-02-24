// 2 Sum
// Pair Sum

// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list 
// of all pairs of elements such that each sum of elements of each pair equals 'S'.

// Note:
// Each pair should be sorted i.e the first value should be less than or equals to the second value. 
// Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have
// the same first value, the pair with a smaller second value should come first.

// Sample Input 1:
// 5 5
// 1 2 3 4 5
// Sample Output 1:
// 1 4
// 2 3
// Explaination For Sample Output 1:
// Here, 1 + 4 = 5
//       2 + 3 = 5
// Hence the output will be, (1,4) , (2,3).
#include<bits/stdc++.h>
using namespace std;

// Function to find pairs whose sum equals a given value
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    // Vector to store pairs whose sum equals 's'
    vector<vector<int>> ans;
    
    // Nested loops to iterate over each pair of elements in the array
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            // If the sum of the current pair equals 's'
            if(arr[i] + arr[j] == s) {
                // Create a vector to store the pair
                vector<int> temp;
                // Store the smaller and larger elements of the pair
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                // Add the pair to the result vector
                ans.push_back(temp);
            }
        }
    }
    
    // Sort the result vector lexicographically
    sort(ans.begin(), ans.end());
    
    // Return the vector containing pairs whose sum equals 's'
    return ans;
}

int main() {
    // Example usage
    vector<int> arr = {3, 5, 2, 4, 8, 6, 7, 1};
    int targetSum = 9;

    // Find pairs whose sum equals the target sum
    vector<vector<int>> result = pairSum(arr, targetSum);

    // Output the pairs
    cout << "Pairs with sum " << targetSum << ":" << endl;
    for (auto pair : result) {
        cout << pair[0] << " " << pair[1] << endl;
    }

    return 0;
}
