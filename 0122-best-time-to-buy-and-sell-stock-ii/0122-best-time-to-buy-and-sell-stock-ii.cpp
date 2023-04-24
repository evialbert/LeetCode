class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int max_profit = 0;
       for(int i=n-2;i>=0;i--)
       {
           max_profit = max(max_profit, prices[i+1] - prices[i]+ max_profit);
       }
       return max_profit;  
    }
};