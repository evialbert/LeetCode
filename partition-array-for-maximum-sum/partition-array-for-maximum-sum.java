class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int[] dp = new int[arr.length];
        Arrays.fill(dp,-1);
        return solve(0, arr.length - 1,arr,k,dp);

    }
    
    public static int solve(int start,int end,int[] arr, int k,int[] dp){
        if(start > end){
            return 0;
        }
        
        if(dp[start] != -1){
            return dp[start];
        }
        int max = arr[start];
        int ans = Integer.MIN_VALUE;
        for(int i = start; i < start + k && i <= end; i++){
            max = Math.max(arr[i],max);
            //division
            int multiple = (i - start + 1);
            int temp = multiple * max;
            int x = temp + solve(i + 1, end,arr,k,dp);
            ans = Math.max(ans,x);
        }
        return dp[start] = ans;
    }
}