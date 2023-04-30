class Solution {
public:
    int find_path(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i==n-1) return triangle[i][j]; //base condition: if all rows are covered then return; 
        
        if(dp[i][j] != -1) return dp[i][j]; //condition for using calculated path sum by dp
        
        //We can move in two directions bottom(i+1,j) and bottom right(i+1,j+1)
        //so we add current path value and move in these directions 
        int bottom = triangle[i][j] + find_path(i+1, j, n, triangle, dp); 
        int bottom_right = triangle[i][j] + find_path(i+1, j+1, n, triangle, dp);
        
        //store minimum path sum in dp for further use
        return dp[i][j] = min(bottom, bottom_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {   
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n,-1)); //create vector dp for storing calculated path sum
        return find_path(0, 0, n, triangle, dp); //return minimum path sum
    }
};