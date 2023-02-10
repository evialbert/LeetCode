class Solution {
public:
    int recur(int i, vector<int>& p, bool buy, vector<vector<int>>& dp){
        if(i>=p.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy]; 
        int profit=0;
        if(buy) profit = max(-p[i]+recur(i+1, p, false, dp), recur(i+1, p, true, dp));
        else profit = max(p[i]+recur(i+2, p, true, dp), recur(i+1, p, false, dp));
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recur(0, prices, true, dp);
    }
};