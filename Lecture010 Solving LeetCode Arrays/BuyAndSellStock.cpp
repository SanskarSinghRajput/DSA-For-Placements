// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to 
// maximize your profit by choosing a single day to buy one stock and choosing a different day in the future
// to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

class Solution {
public:
    // Best Optimized Approach - O(n) time complexity
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int lsf = INT_MAX; // least so far 
        int op = 0; //overall profit
        int pist = 0; // profit if sold today

        for(int i=0;i<size;i++){
            // if we found new buy value which is more small then previous one
            if(prices[i] < lsf){
               // update our least so far
               lsf = prices[i];
            }
            // calculating profit if sold today by, Buy - sell
            pist = prices[i] - lsf;
            // if pist is more then our previous overall profit
            if(op < pist){
              // update overall profit
              op = pist; 
            }
        }
        return op; // return overall profit
    }

    // Brute Force Approach it give (TLE) - O(n)2 time complexity
    int maxProfit(vector<int>& prices) {
        int size = prices.size(); 
        int maxans = 0;
        for(int i=0;i<size;i++){
            for(int j=i+1; j<size; j++){
               int diff = prices[j] - prices[i];
               if(diff > 0){
                maxans = max(maxans,diff);
               }
            }
        }
        return maxans;
    }
};