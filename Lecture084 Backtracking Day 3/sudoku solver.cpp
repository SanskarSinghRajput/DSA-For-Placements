#include <bits/stdc++.h>
bool isSafe(int row,int col,vector<vector<int>>& board,int val){
    for(int i=0;i<board.size();i++){
        //for row check
        if(board[row][i]==val)
          return false;

        //for col check
        if(board[i][col]==val)
          return false;

        //3*3 matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val)
          return false;
    }
    return true;
}
bool solve(vector<vector<int>>& board){
    int n = board.size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        // recursive call
                        bool nextSolnPossible = solve(board);
                        if(nextSolnPossible){
                            return true;
                        }
                        else{
                            //backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
     return true;
} 
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}