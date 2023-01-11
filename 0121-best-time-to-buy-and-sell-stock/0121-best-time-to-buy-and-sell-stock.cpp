class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mintilnow = prices[0];

        int profit = INT_MIN;

        for(int i=0;i<prices.size();i++)
        {
            if(mintilnow > prices[i]) mintilnow = prices[i];
            if(prices[i] - mintilnow > profit) profit = prices[i] - mintilnow;
         
        }
        return profit;

    }
};