// 464. Can I Win
/* In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player
who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without 
replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a
win, otherwise, return false. Assume both players play optimally. */

// Example 1:
// Input: maxChoosableInteger = 10, desiredTotal = 11
// Output: false
// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.

// Example 2:
// Input: maxChoosableInteger = 10, desiredTotal = 0
// Output: true

// Example 3:
// Input: maxChoosableInteger = 10, desiredTotal = 1
// Output: true

class Solution {
public:
    // dp array holds result of any number choosing combination 
    // max number 20, so max range = 2^22-1 as we consider bit position 1 to 20
    int dp[4194303]={};

    // check bit position is 1 means, that position number is already taken
    bool checkSetBit(int track, int pos){
        return ((track>>pos) & 1)==1;
    }

    // returns if player1 or player2 wins the game
    // player == true means player1 and player == false means player2
    // winning score of player1 is 1 and player2 is -1
    int game(int l, int h, int desiredTotal, int track, bool player){
        // base case: desiredTotal<=0 then current player lost and previous player won
        // if current player is player1 then winner is player2 so winning score is -1
        // if current player is player2 then winner is player1 so winning score is 1
        if(desiredTotal<=0) 
           return dp[track] = player?-1:1;

        // return precalculated value
        if(dp[track]!=0) 
           return dp[track];
 
        // result if current player wins or loss
        int result;
        if(player){
            result = INT_MIN;
            for(int i=l; i<=h; i++){
                // use bitwise track to check if current number i is taken 
                if(!checkSetBit(track, i)){
                   // take number i which is not taken already and call recursion for next player setting the ith pos 1 in track
                    // player1 wants to maximize the score always
                    result = max(result,game(l,h,desiredTotal-i,track|(1<<i),!player));
                    
                    // player1 won then return result
                    if(result==1)
                       return dp[track] = 1; 
                }
            }
        }
        else {
            result = INT_MAX;
            for(int i=l;i<=h;i++){
                if(!checkSetBit(track,i)){
                    // player2 wants to minimize the score always
                    result = min(result,game(l,h,desiredTotal-i,track|(1<<i),!player));
                    
                    // player 2 won then return result
                    if(result==-1) 
                       return dp[track] = -1;
                }    
            }            
            
        }

        dp[track] = result;
        return result;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // desiredTotal == 0 then player1 wins
        if(desiredTotal == 0) 
           return true;

        // sum of all numbers in range 1 to max choosable number = (n*(n+1))/2;
        int sum = (maxChoosableInteger * (maxChoosableInteger+1))/2;

        // if sum < desiredTotal then there is no way to win and so return false
        if(sum<desiredTotal) 
           return false;

        int track = 0;

        // player1 wins using an optimal move
        return game(1, maxChoosableInteger, desiredTotal, track, true) == 1;
    }
};