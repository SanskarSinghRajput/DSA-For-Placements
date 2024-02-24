// Find All Duplicates in an Array

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] 
// and each integer appears once or twice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

// Example 2:
// Input: nums = [1,1,2]
// Output: [1]

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> duplicates;

    // Count occurrences of each element
    for(int num : nums) {
        map[num]++;
    }

    // Check for elements with a count of exactly 2
    for(auto& pair : map) {
        if(pair.second == 2) {
            duplicates.push_back(pair.first);
        }
    }

    return duplicates;
}

int main() {
    // Example usage
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);

    cout << "Duplicates: ";
    for(int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
