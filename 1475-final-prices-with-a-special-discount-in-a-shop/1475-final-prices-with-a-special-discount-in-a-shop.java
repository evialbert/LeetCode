class Solution {
    public int[] finalPrices(final int[] prices) {
        final int[] result = new int[prices.length];
        for (int i=0; i<prices.length; i++) {
            int discount = 0;
            for (int j=i+1; j<prices.length && discount == 0; j++) {
                discount = prices[i]>=prices[j]?prices[j]:0;
            }
            result[i] = prices[i] - discount;
        }
        return result;
    }
}