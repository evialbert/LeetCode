public class Solution {
    public int MinXor(int[] nums, int k) {
        int n = nums.Length;
        int[] prefixXor = new int[n + 1];
        
        for (int i = 0; i < n; i++)
            prefixXor[i + 1] = prefixXor[i] ^ nums[i];

        int[,] dp = new int[n + 1, k + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i, j] = int.MaxValue;

        dp[0, 0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= Math.Min(k, i); j++) {
                for (int p = j - 1; p < i; p++) {
                    int xor = prefixXor[i] ^ prefixXor[p];
                    dp[i, j] = Math.Min(dp[i, j], Math.Max(dp[p, j - 1], xor));
                }
            }
        }

        return dp[n, k];
    }
}