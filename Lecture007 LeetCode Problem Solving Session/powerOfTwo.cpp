// Power of Two

// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2powerX.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: 2power0 = 1

// Example 2:
// Input: n = 16
// Output: true
// Explanation: 2power4 = 16

// Example 3:
// Input: n = 3
// Output: false

#include <bits/stdc++.h>
using namespace std;

//--------Approach1-------
bool isPowerOfTwo(int n) {  
    int ans = 1;    
    for(int i = 0; i <= 30; i++) {    
        //cout<<" ans "<<ans <<endl;
        if(ans == n)
            return true;
        if(ans < INT_MAX/2)
            ans = ans * 2;   
    }
    return false;
}

// Approach 2 (Optimized) using Bit manipulation
bool isPowerOfTwo(int num) {
    // A number is a power of 2 if it has only one bit set
    // So, bitwise AND of the number and (number - 1) should be zero
    return (num > 0) && ((num & (num - 1)) == 0);
}

// -------------DRY RUN------------------
// user inputs the number 8.
// The isPowerOfTwo function is called with num = 8.
// num is greater than 0.
// (num - 1) equals 7.
// Bitwise AND operation between num (binary: 1000) and (num - 1) (binary: 0111) results in 0000, which is zero.
// 1000 & 0111 == 0000
// Since the result is zero, the function returns true.
// otherwise return false

// Since isPowerOfTwo(8) returns true, the program prints "8 is a power of 2.

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isPowerOfTwo(number)) {
        std::cout << number << " is a power of 2." << std::endl;
    } else {
        std::cout << number << " is not a power of 2." << std::endl;
    }

    return 0;
}
