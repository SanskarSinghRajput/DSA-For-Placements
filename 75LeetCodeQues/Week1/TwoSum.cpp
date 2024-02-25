#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1 - Brute Force 
    vector<int> twoSum(vector<int>& nums, int target){
        int n = nums.size();

        // Iterate through each element in the vector
        for(int i = 0; i < n; i++) {
            // Iterate through each element after the current element
            for(int j = i + 1; j < n; j++) {
                // Check if the sum of the current element and the element after it equals the target
                if(nums[i] + nums[j] == target) {
                    // If found, return the indices of the two numbers
                    return {i, j};
                }
            }
        }
        
        // If no solution is found, return {-1, -1}
        return {-1, -1};
    }

    // Approach 2 - Using (Two-pass Hash Table)
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store the index of previously visited elements
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            // Storing the index of the current element in the map
            numMap[nums[i]] = i;
        }

        // Iterating through the array
        for (int i = 0; i < n; i++) {
            int moreNeeded = target - nums[i];

            // numMap.count(moreNeeded): This checks if the element moreNeeded exists as a key in the numMap.
            // numMap.count(moreNeeded) returns 1 if the element is found and 0 otherwise.

            // numMap[moreNeeded] != i: This checks if the index i is not equal to the index stored in the map for the
            // key moreNeeded. This condition ensures that the same element is not used twice to get the target sum.
            
            // Checking if the moreNeeded exist in map to achieve the target sum 
            if(numMap.count(moreNeeded) && numMap[moreNeeded] != i){
               return {i, numMap[moreNeeded]};
            }
        }

        // No solution found
        return {-1, -1};
    }

    // Approach 3 - (One-pass Hash Table) Optimized Apporach
    vector<int> twoSum(vector<int>& nums, int target){
        // Map to store the index of previously visited elements
        map<int,int> mpp;
        int n = nums.size();

        // Iterating through the array
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int moreNeeded = target - num;

            // Checking if the moreNeeded exist in map to achieve the target sum 
            if(mpp.find(moreNeeded) != mpp.end()){
                // If found, return the indices of the two numbers
                return {mpp[moreNeeded], i};
            }

            // Storing the index of the current element in the map
            mpp[num] = i;
        }

        // If no solution is found, return {-1, -1}
        return {-1, -1};
    }

};

int main(){
    // Example usage of the twoSum function
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    // Printing the result
    cout<<"Indices of the two numbers: "<< result[0] <<", "<< result[1]<<endl;

    return 0;
}
