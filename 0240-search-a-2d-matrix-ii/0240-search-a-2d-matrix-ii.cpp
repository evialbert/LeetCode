class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
				//initializing row and col pointers
				int row = 0, col = matrix[0].size() - 1;
        
        while(row < n && col >= 0){
            if(matrix[row][col] == target)
                return true;
            if(target < matrix[row][col] )
                --col;
            else
                ++row;
        }
        return false;
    }
};