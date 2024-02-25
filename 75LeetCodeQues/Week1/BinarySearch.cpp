// 704 Binary Search

class Solution {
public:
    // Function to perform binary search on a sorted vector
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        // Loop until start index is less than or equal to end index
        while (start <= end) {
            // Calculate the mid index
            mid = start + (end - start) / 2;
            
            // If the target is found at mid index, return mid
            if (nums[mid] == target)
                return mid;

            // If the target is smaller than the value at mid index,
            // update the end index to search the left half
            if (nums[mid] > target)
                end = mid - 1;
            // If the target is larger than the value at mid index,
            // update the start index to search the right half
            else
                start = mid + 1;
        }
        
        // If target is not found in the vector, return -1
        return -1;
    }
};