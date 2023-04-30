class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = n-2;row>=0;row--){
            for(int col=0;col<n;col++){
                if(col == 0){
                    matrix[row][col] = min(matrix[row][col]+matrix[row+1][col],matrix[row][col]+matrix[row+1][col+1]);
                }else if(col == n-1){
                    matrix[row][col] = min(matrix[row][col]+matrix[row+1][col-1],matrix[row][col]+matrix[row+1][col]);
                }else{
                    matrix[row][col] = min(matrix[row][col]+matrix[row+1][col],min(matrix[row][col]+matrix[row+1][col-1],matrix[row][col]+matrix[row+1][col+1]));
                }
            }
        }

        int ans = *min_element(matrix[0].begin(),matrix[0].end());
        return ans;
    }
};