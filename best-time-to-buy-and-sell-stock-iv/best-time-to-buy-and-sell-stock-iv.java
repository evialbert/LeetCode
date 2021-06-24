class Solution {
    public int maxProfit(int k, int[] prices) {
        if(prices.length == 0){
            return 0;
        }
        int[][] daysProfit = new int[k+1][prices.length];
        
        for(int t=1; t<k+1; t++){
            int max = Integer.MIN_VALUE;
            for(int d=1; d<prices.length; d++){
                max = Math.max(max, daysProfit[t-1][d-1] - prices[d-1]);
                
                if(max + prices[d] > daysProfit[t][d-1]){
                    daysProfit[t][d] = max + prices[d];
                }else{
                    daysProfit[t][d] = daysProfit[t][d-1];
                }
            }
        }
        
        return daysProfit[k][prices.length - 1];
    }
}