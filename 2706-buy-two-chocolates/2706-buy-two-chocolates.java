class Solution {
    public int buyChoco(int[] prices, int money) {
        int first=prices[0];
        int second=prices[1];
        if(prices[0]>prices[1]){
            first=prices[1];
            second=prices[0];
        }
        for(int i=2;i<prices.length;i++){
            int p=prices[i];
            if(p<first){
                second=first;
                first=p;
            }
            else if(p>=first && p<second){
                second=p;
            }
        }
        int sum=first+second;
        return sum>money?money:money-sum;
    }
}