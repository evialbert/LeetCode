class Solution {
    public long maximumProfit(int[] prices, int k) {
long[][][]arr=new long[prices.length][k+1][3];
        for(int i=0;i<prices.length;i++){
            for(int j=0;j<=k;j++){
                Arrays.fill(arr[i][j],-1);
            }
        }
        return helper(prices,k,arr,0,0,0);
    }
    public static long helper(int[]prices,int k,long [][][]dp,int day,int txn,int state){
        if(day==prices.length) {
            if(state==0)return 0;
            return Long.MIN_VALUE/2;
        }
        if(txn==k&&state!=0)return 0;
        if(dp[day][txn][state]!=-1)return dp[day][txn][state];
        long profit;
        if(state==0){
            long skip=helper(prices,k,dp,day+1,txn,0);
            profit=skip;
            if(txn<k){
                long buylong=-prices[day]+helper(prices,k,dp,day+1,txn,1);
                long sellshort=prices[day]+helper(prices,k,dp,day+1,txn,2);
                profit=Math.max(skip,Math.max(sellshort,buylong));
            }
        }else if(state==1){
            long hold=helper(prices,k,dp,day+1,txn,1);
            long sell=prices[day]+helper(prices,k,dp,day+1,txn+1,0);
            profit=Math.max(hold,sell);
        }else{
            long hold=helper(prices,k,dp,day+1,txn,2);
            long buyagain=-prices[day]+helper(prices,k,dp,day+1,txn+1,0);
            profit=Math.max(hold,buyagain);
        }
        return dp[day][txn][state]=profit;
    }
}