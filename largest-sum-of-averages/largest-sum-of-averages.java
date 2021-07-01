class Solution {
    private static final int INF = (int) 2e9;
    
    public double largestSumOfAverages(int[] A, int K) {
        Map<Integer, Map<Integer, Double>> memo = new HashMap<>();
        return dfs(A, memo, A.length, K);
    }
    
    private double dfs(int[] A, Map<Integer, Map<Integer, Double>> memo, int n, int k) {
        if (n == 0 && k == 0) {
            return 0;
        }
        
        if (n < k || k <= 0) {
            return -INF;
        }
        
        Double value = memo.computeIfAbsent(n, z -> new HashMap<>()).get(k);
        if (value != null) {
            return value;
        }
        
        int sum = 0;
        double best = -INF;
        for (int l = 1; l <= n; l++) {
            sum += A[n - l];
            best = Math.max(best, (double) sum / l + dfs(A, memo, n - l, k - 1));
        }
        
        memo.get(n).put(k, best);
        return best;
    }
}