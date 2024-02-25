// 169 Majority Element
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp; // unordered map to store the frequency of each number
        int max = 0; // max variable stores the maximum count of a number
        int ans = 0; // ans stores the number which has the majority (initialized with 0)
        
        // Iterate through the input vector to count the frequency of each number
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        // Iterate through the map to find the number with the highest frequency
        for(auto i : mp){
            // If the frequency of the current number is greater than max
            if(i.second > max){ 
                max = i.second; // Update max with the current frequency
                ans = i.first; // Update ans with the current number
            }
        }        
        return ans; // Return the number which appears the most
    }

    // Approach 2
    int majorityElement(vector<int>& nums){
        map<int,int> m; // unordered map to store the frequency of each number
        int n = nums.size();
        // Iterate through the input vector to count the frequency of each number
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        map<int, int>::iterator it = m.begin();
        // Iterate through the map and print the elements
        while (it != m.end()){
            if(it->second>n/2)
               return it->first;
            it++;
        }
        return 0;
    }
};

int main(){
    vector<int> nums = {2,2,3,3,3,2,2};

    Solution sol;
    int result = sol.majorityElement(nums);
    cout << "The number that occurs more frequently in the array is: " << result << endl;
    
    return 0;
}