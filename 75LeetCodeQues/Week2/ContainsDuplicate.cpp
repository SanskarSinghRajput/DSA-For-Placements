// 217. Contains Duplicate

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 4 (Using Hashmap Optimized Approach)
    // The time complexity of this approach is O(n), where n is the length of the array.
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq; // unordered map to store the frequency of each number
          
        // Iterate through the input vector
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++; // Increment the frequency of the current number
            
            // If the frequency of the current number is greater than 1, it means it's a duplicate
            if(freq[nums[i]] > 1)
                return true; // Return true as soon as a duplicate is found
        }
        // If no duplicates are found, return false
        return false;
    }

    // Approach 3 (Using HashSet) 
    // The time complexity of this approach is O(n), where n is the length of the array.
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0; i<nums.size();i++){
            set.insert(nums[i]);
        }
        // if it contains duplicate then the size of 
        // set will not equal to the length of the array
        if(set.size() < nums.size())
            return true;
        return false; 
    }

    // Approach 2 (Using Sorting)
    // The time complexity of this approach is O(n log n), where n is the length of the array.
    bool containsDuplicate(vector<int>& nums){
        // Sort the input vector in ascending order
        sort(nums.begin(), nums.end()); 
        int n = nums.size(); // Get the size of the sorted vector
        
        // Iterate through the sorted vector starting from the second element
        for(int i = 1; i < n; i++){
            // If the current element is equal to the previous element, it means there's a duplicate
            if(nums[i] == nums[i - 1])
                return true; // Return true as soon as a duplicate is found
        }
        // If no duplicates are found, return false
        return false;
    }

    // Approach 1 (Brute Force Approach Not Optimal it give TLE)
    // The time complexity of this approach is O(n)square, where n is the length of the array.
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};