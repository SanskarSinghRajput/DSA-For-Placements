// Sort 0 1 2
// You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s.
// Write a solution to sort this array/list.

// Sample Input 1 :
// 0 1 2 2 1 0
// Sample Output 1 :
// 0 0 1 1 2 2

// Sample Input 2 :
// 0 1 2 1 2 1 2
// Sample Output 2 :
// 0 1 1 1 2 2 2

#include <bits/stdc++.h> 
using namespace std;

// Function to sort an array of 0s, 1s, and 2s
void sort012(int *arr, int n) {
    // Initialize three pointers: low, mid, and high
    int low = 0, mid = 0, high = n - 1;
    
    // Loop through the array until mid crosses high
    while (mid <= high) {
        // If the current element is 0
        if (arr[mid] == 0) {
            // Swap the current element with the element at 'low'
            swap(arr[low], arr[mid]);
            // Move 'low' and 'mid' pointers to the next positions
            low++;
            mid++;
        } 
        // If the current element is 1
        else if (arr[mid] == 1) {
            // Move 'mid' pointer to the next position
            mid++;
        } 
        // If the current element is 2
        else {
            // Swap the current element with the element at 'high'
            swap(arr[mid], arr[high]);
            // Move 'high' pointer to the previous position
            high--;
        }
    }
}

int main() {
    // Example usage
    int arr[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array of 0s, 1s, and 2s
    sort012(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
