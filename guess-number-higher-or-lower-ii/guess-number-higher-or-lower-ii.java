class Solution {
   public int getMoneyAmount(int n) {
    int[] arr = new int[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = i+1;
    }
    int[][] dp = new int[n][n];
    for(int[] dpi : dp) {
        Arrays.fill(dpi, -1);
    }
    return find(arr, 0, n-1, dp);
}

public int find(int[] arr, int from, int to, int[][] dp) {
    if(to <= from) return 0;
    if(dp[from][to] != -1) {
        return dp[from][to];
    }
    int min = Integer.MAX_VALUE;
    for(int i = from; i <= to; ++i) {
        int left = find(arr, from, i-1, dp);
        int right = find(arr, i+1, to, dp);
        int cost = Math.max(left, right) + arr[i];
        min = Math.min(min, cost);
    }
    dp[from][to] = min;
    return min;
}
}