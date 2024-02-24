// Unique Number Of Occurences

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique
// or false otherwise.

// Example 1:
// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Example 2:
// Input: arr = [1,2]
// Output: false

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> map;
    set<int> s;
    
    // Count occurrences of each element
    for(int i : arr){
        map[i]++;
    }
    
    // Store the counts in a set to check for uniqueness
    for(auto x : map){
        s.insert(x.second);
    }
    
    // If the number of unique counts is equal to the total number of unique elements,
    // then each element has a unique count of occurrences
    return map.size() == s.size();
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    if (uniqueOccurrences(arr)) {
        cout << "Each element has a unique count of occurrences." << endl;
    } else {
        cout << "There are elements with non-unique counts of occurrences." << endl;
    }
    return 0;
}
