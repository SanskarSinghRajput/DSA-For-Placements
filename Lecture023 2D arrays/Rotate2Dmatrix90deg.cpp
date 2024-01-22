class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // first Transpose the matrix
        for(int i=0;i<n-1;i++){
            for(int j=i+1; j<n; j++){
                if( i!=j ){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        // then reverse each row of the matrix
        for(int i=0;i<n;i++){
           reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};