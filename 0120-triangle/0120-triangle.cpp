class Solution {
public:

    int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i >= triangle.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int res = triangle[i][j] + min(helper(i+1,j,triangle,dp), helper(i+1,j+1,triangle,dp));

        return dp[i][j] = res;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        int ans = helper(0,0,triangle,dp);
        return ans;
    }

};
