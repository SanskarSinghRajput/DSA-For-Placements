// 53 Maximum Subarray with maximum sum
#include <vector>
#include <climits> // Required for using INT_MIN

using namespace std;

class Solution {
public:
    // Function to find the maximum sum of contiguous subarray
    int maxSubArray(vector<int>& nums) {
        int sum = 0; // Variable to store the current sum of subarray
        int maxi = INT_MIN; // Variable to store the maximum sum found so far (initialized with minimum integer value)
        
        // Iterate through each element of the input vector
        for (auto i : nums) {
            sum += i; // Add the current element to the sum
            
            // Update maxi with the maximum of sum and maxi
            maxi = max(sum, maxi);
            
            // If sum becomes negative, reset it to 0
            if (sum < 0)
                sum = 0;
        }
        
        return maxi; // Return the maximum sum found
    }
};
