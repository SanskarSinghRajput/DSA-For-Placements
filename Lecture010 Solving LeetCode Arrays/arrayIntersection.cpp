//  Intersection Of Two Sorted Arrays

// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted 
// in non-decreasing order. You have to find the intersection of these two arrays.
// Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

// Sample Input 1 :
// 6 4
// 1 2 2 2 3 4
// 2 2 3 3
// Sample Output 1 :
// 2 2 3
// Explanation for Sample Input 1 :
// For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.

// Sample Input 2 :
// 3 2
// 1 2 3
// 3 4 
// Sample Output 2 :
// 3   
// Explanation for Sample Input 2 :
// For the second test case, only 3 is common so we print 3.


#include <vector>
#include <iostream>
using namespace std;

//--------------Two Pointer Approach---------------------
// Function to find the intersection of two sorted arrays
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    // Initialize two pointers i and j to iterate through arr1 and arr2 respectively
    int i = 0, j = 0;

    // Vector to store the intersection elements
    vector<int> ans;

    // Traverse both arrays while there are elements remaining in both arrays
    while (i < n && j < m) {
        // If both elements are equal, it's a common element
        if (arr1[i] == arr2[j]) {
            // Add the common element to the intersection vector
            ans.push_back(arr1[i]);
            // Move both pointers to the next elements in both arrays
            i++;
            j++;
        }
        // If element of arr1 is smaller, move the pointer for arr1
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        // If element of arr2 is smaller, move the pointer for arr2
        else {
            j++;
        }
    }
    // Return the vector containing intersection elements
    return ans;
}

int main() {
    // Example usage
    vector<int> arr1 = {1, 3, 4, 5, 7};
    vector<int> arr2 = {2, 3, 5, 6};
    int n = arr1.size();
    int m = arr2.size();

    vector<int> intersection = findArrayIntersection(arr1, n, arr2, m);

    // Output the intersection elements
    cout << "Intersection: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
