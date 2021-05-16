class Solution {
    public int maxProfit(int[] prices, int fee) {
        if(prices.length<=1)
            return 0;
       int ans=0;
       int bsp=-prices[0];
       int ssp=0;
        for(int i=1;i<prices.length;i++){
            bsp=Math.max(bsp,ssp-prices[i]);
            ssp=Math.max(ssp,prices[i]-fee+bsp);
        }
        return Math.max(ssp,bsp);
    }
}