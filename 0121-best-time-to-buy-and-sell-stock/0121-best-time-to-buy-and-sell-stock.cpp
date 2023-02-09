class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int dp[n];
        int profit=0;
        int mx=prices[n-1];
        dp[n-1]=-1;
        
        for(int i=n-2;i>=0;i--) {
            if(prices[i]>mx) {
                mx=prices[i];
                dp[i]=-1;
            }
            else {
                dp[i]=mx;
                profit=max(profit,dp[i]-prices[i]);
            }    
        }
        return profit;
    }
};