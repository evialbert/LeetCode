class Solution {
   public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int n = satisfaction.length;        
        if (satisfaction[n-1]<=0) return 0;
        int[] dp = new int[n+1];
        int sum = 0;
        int ps = 0;
        for (int i=n-1;i>=0;i--) {
            ps = ps + satisfaction[i];
            dp[i] = dp[i+1] + ps;
            if (dp[i]>sum) {
                sum = dp[i];
            }
        }
        return sum;
    }
}