class Solution {
    int dfs(vector<int>& prices, vector<vector<int>> &dp, int idx, int &fee, int buy)
    {
        if(idx == prices.size())
            return 0;
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        int val = 0;
        if(!buy)
        {
            val = max(dfs(prices, dp, idx+1, fee, buy+1)-prices[idx], dfs(prices, dp, idx+1, fee, buy));
        }
        else
        {
            val = max(dfs(prices, dp, idx+1, fee, buy-1)+prices[idx]-fee, dfs(prices, dp, idx+1, fee, buy));
        }
        return dp[idx][buy] = val;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return dfs(prices, dp, 0, fee, 0);
    }
};