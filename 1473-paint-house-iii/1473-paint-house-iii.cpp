class Solution {
private:
    vector<vector<vector<int>>> dp;
    int helper(int i, int col, int neig, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(neig > target) return INT_MAX/2;
        if(i == m) return target == neig ? 0: INT_MAX/2;
        if(dp[i][col][neig] != -1) return dp[i][col][neig];
            int ans = INT_MAX/2;
            if(houses[i] == 0){
                for(int j = 0; j<n; ++j){
                    ans = min(ans, cost[i][j] + helper(i + 1, j + 1, (j + 1 == col? neig : neig + 1), houses, cost, m, n, target));
                }
            }
            else{
                ans = min(ans, 0 + helper(i + 1, houses[i], (houses[i] == col? neig : neig + 1), houses, cost, m, n, target));
            }
        return dp[i][col][neig] = ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp.resize(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        int ans = helper(0, 0, 0, houses, cost, m, n, target);
        return ans == INT_MAX/2? -1 : ans;
    }
}; 