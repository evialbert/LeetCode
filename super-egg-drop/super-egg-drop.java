class Solution {
    
    int[][] dp = new int[101][10001];
    
    public int solve(int k, int n) {
        if (n <= 1 || k == 1)
            return n;
        
        if (dp[k][n] > 0)
            return dp[k][n];
        
        int best = Integer.MAX_VALUE;
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            int breaks = solve(k - 1, mid - 1);
            int notBreaks = solve(k, n - mid);
            dp[k][n] = Math.min(best, Math.max(breaks, notBreaks) + 1);
            if (breaks == notBreaks)
                break;
            else if (breaks < notBreaks)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return dp[k][n];
    }
    
    public int superEggDrop(int k, int n) {
        return solve(k, n);
    }
}