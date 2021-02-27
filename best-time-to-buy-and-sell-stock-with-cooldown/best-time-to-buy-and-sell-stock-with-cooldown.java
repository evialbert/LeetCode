class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0;
        

        int buy = - prices[0];
        int sell = 0;
        int cooldown = 0;
        for (int i = 1; i < prices.length; i++) {
            int price = prices[i];
            
            int tempBuy = Math.max(buy, cooldown - price);
            cooldown = sell;
            sell = Math.max(sell, buy + price);
            
            buy = tempBuy;
        }
        
        return sell;
    }
}