class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        if(n == 1) return questions[0][0];
        // dp[i] represents the maximum points that can be get from ith question to nth question. 
        long[] dp = new long[n];
        // move from index n to index 0;
        dp[n-1] = questions[n-1][0];
        for(int i = n-2; i >= 0; i--){
            long rest = i + questions[i][1] + 1 < n ? dp[i + questions[i][1] + 1] : 0;
            dp[i] = Math.max(dp[i+1], questions[i][0] + rest);
        }
        return dp[0];
    }
}
