class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size() , n = matrix[0].size();
        int i = 0;
        for(int j=0;j<m;j++)
        {
            if(matrix[j][0]==target) return true;
            if(matrix[j][0]>target) break;
            i = j;   
        }
        for(int k = 0;k<n;k++)
        {
            if(matrix[i][k]==target)
                return true;
        }
        return false;
    }
};