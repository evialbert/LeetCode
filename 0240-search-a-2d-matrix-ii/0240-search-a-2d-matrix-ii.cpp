class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0 , j = matrix[0].size() - 1;
        int n = matrix.size();
        while(i < n && j >= 0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};