#include<iostream>
#include<vector>
using namespace std;
vector<int> wavePrint(vector<vector<int> > arr, int nRows, int mCols)
{
    vector<int> ans;
    
    for(int col=0; col<mCols; col++) {
        
        if( col&1 ) {
            //odd no. of col -> Bottom to top
            
            for(int row = nRows-1; row>=0; row--) {
                //cout << arr[row][col] <<" ";
                ans.push_back(arr[row][col]);
            }    
        }
        else
        {
            //even no. of col-> top to bottom
            for(int row = 0; row<nRows; row++) {
                //cout << arr[row][col] << " ";
                ans.push_back(arr[row][col]);
            }
        }   
    }
    return ans;
}

vector<int> rowWaveForm(vector<vector<int>> &mat) {
    vector<int> ans;
    int n = mat.size();
    int m = mat[0].size();
    for(int startRow=0;startRow<n;startRow++){
        // even no. of row Left->Right
        if((startRow & 1) == 0){
            for(int i=0;i<m;i++)
               ans.push_back(mat[startRow][i]);
        }

        // odd no. of row Right->Left
        else{
            for(int i=m-1;i>=0;i--)
               ans.push_back(mat[startRow][i]);
        }
    }
    return ans;
}