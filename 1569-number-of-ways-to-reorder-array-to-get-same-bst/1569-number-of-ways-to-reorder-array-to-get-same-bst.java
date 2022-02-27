class Solution {
    long mod = 1_000_000_007, dp[][];
    public int numOfWays(int[] nums) {
        dp = getYang(nums.length);
        List<Integer> list = new ArrayList<>();      
        for (int n : nums) list.add(n);
        return (int) (dfs(list) - 1);
    }
    
    private long dfs(List<Integer> l) {
        if (l.size() < 3) return 1;
        int root = l.get(0);
        List<Integer> left = new ArrayList<>(), right = new ArrayList<>();
        for (int i = 1; i < l.size(); i++) {
            if (l.get(i) < root) left.add(l.get(i));
            else right.add(l.get(i));
        }
        return dp[left.size() + right.size()][left.size()] % mod * dfs(left) % mod * dfs(right) % mod;
    }
    
    private long[][] getYang(int n) {
        long[][] res = new long[n + 1][n + 1];
        for (int i = 1; i <= n; i++) res[i][0] = res[i][i] = 1;
        for (int i = 2; i <= n; i++) 
            for (int j = 1; j < i; j++) 
                res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]) % mod; 
        return res;
    }
}