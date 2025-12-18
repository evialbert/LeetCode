class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        int n = prices.length;
        long profitPrefix[] = new long[n];
        long pricePrefix[] = new long[n];
        profitPrefix[0] = (long) prices[0] * strategy[0];
        pricePrefix[0] = prices[0];
        for(int i = 1 ; i < n ; ++i){
            profitPrefix[i] = profitPrefix[i-1] + (long)prices[i]*strategy[i];
            pricePrefix[i] = pricePrefix[i-1]+prices[i];
        }
        long baseProfit = profitPrefix[n-1];
        long res = baseProfit;
        int i = 0 , j = k-1;
        int mid = k / 2;
        while(j < n){
            long oldWindow = i == 0 ? profitPrefix[j] : profitPrefix[j] - profitPrefix[i-1] ;
            long newWindow = mid == 0 ? pricePrefix[j] : pricePrefix[j] - pricePrefix[mid-1];
            long newSum = baseProfit - oldWindow + newWindow;
            res = Math.max(res,newSum);
            ++i;
            ++mid;
            ++j;
        }
        return res;

    }
}