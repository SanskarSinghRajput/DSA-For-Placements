// 15 3Sum

// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets
// present in the array which adds up to a given number K.
// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three 
// indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

// Sample Input 1:
// 1
// 5
// 10 5 5 5 2
// 12
// Sample Output 1:
// 5 5 2
// Explanation for Sample Input 1:
// 5 5 2 is the only triplet that adds up to 15. Note that the order of the output doesn’t matter, 
// so 5 2 5 or 2 5 5 is also acceptable.

#include <bits/stdc++.h>
using namespace std;

// Function to find triplets with given sum K
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    // Set to store unique triplets
    set<vector<int>> hash;
    
    // Sorting the array to use two-pointer technique
    sort(arr.begin(), arr.end());
    
    // Loop through each element as the first element of the triplet
    for (int i = 0; i < n; i++) {
        int low = i + 1, high = n - 1; // Pointers for the remaining two elements
        while (low < high) {
            int current = arr[i] + arr[low] + arr[high]; // Calculate the sum of the triplet
            if (current == K) {
                vector<int> temp = {arr[i], arr[low], arr[high]}; // Create a triplet
                sort(temp.begin(), temp.end()); // Sort the triplet
                hash.insert(temp); // Insert the triplet into the set to remove duplicates
                low++; // Move low pointer ahead to find next potential triplet
                high--; // Move high pointer backward to find next potential triplet
            } else if (current < K) {
                low++; // If the sum is less than K, move low pointer ahead
            } else {
                high--; // If the sum is greater than K, move high pointer backward
            }
        }
    }
    
    // Convert set to vector to return the unique triplets
    vector<vector<int>> ans(hash.begin(), hash.end());
    
    return ans;
}

int main() {
    // Example usage
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int n = arr.size();
    int K = 13;

    // Find triplets with sum K
    vector<vector<int>> triplets = findTriplets(arr, n, K);

    // Output the triplets
    for (auto triplet : triplets) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
}
