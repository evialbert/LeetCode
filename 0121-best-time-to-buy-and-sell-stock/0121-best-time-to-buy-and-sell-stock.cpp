class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        int cost;
        for (int i=1; i<n; i++) {
            cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};