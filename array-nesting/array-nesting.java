class Solution {
    public int arrayNesting(int[] nums) {
        int[] memo = new int[nums.length];
        Arrays.fill(memo, -1);
        
        int ans = 0;
        for(int i = 0; i < nums.length; i++)
            ans = Math.max(ans, dfs(nums, memo, new boolean[nums.length], i));
        
        return ans;
    }
    
    public int dfs(int[] a, int[] memo, boolean[] visited, int x) {
        if(x >= a.length || visited[x]) return 0;
        visited[x] = true;
        if(memo[x] != -1) return memo[x];
        memo[x] = 1 + dfs(a, memo, visited, a[x]);
        return memo[x];
    }
}