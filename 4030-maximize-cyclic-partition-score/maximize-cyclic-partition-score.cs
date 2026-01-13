public class Solution
{
    public long MaximumScore(int[] nums, int k)
    {
        int n = nums.Length;

        // Step 1 — Find index of the minimum element to safely linearize cycle
        int p = 0;
        for (int i = 1; i < n; i++)
            if (nums[i] < nums[p])
                p = i;

        // Forward rotated
        int[] A = new int[n];
        for (int i = 0; i < n; i++)
            A[i] = nums[(p + i) % n];

        // Reverse rotated
        int[] B = new int[n];
        for (int i = 0; i < n; i++)
            B[i] = nums[(p - i + n) % n];

        return Math.Max(Solve(A, k), Solve(B, k));
    }


    private long Solve(int[] a, int k)
    {
        int n = a.Length;

        // dp[t,j] = best score using exactly t partitions for prefix [0..j-1]
        long[,] dp = new long[k + 1, n + 1];

        for (int t = 0; t <= k; t++)
            for (int j = 0; j <= n; j++)
                dp[t, j] = long.MinValue;

        long mn = long.MaxValue, mx = long.MinValue;

        // Base case → 1 segment only
        for (int j = 0; j < n; j++)
        {
            mn = Math.Min(mn, a[j]);
            mx = Math.Max(mx, a[j]);
            dp[1, j + 1] = mx - mn;
        }

        long ans = dp[1, n];

        // DP transitions for t = 2..k
        for (int t = 2; t <= k; t++)
        {
            long bestMinus = long.MinValue;
            long bestPlus  = long.MinValue;

            for (int j = t - 1; j < n; j++)
            {
                // maintain best dp[t-1][x] - a[x] and dp[t-1][x] + a[x]
                bestMinus = Math.Max(bestMinus, dp[t - 1, j] - a[j]);
                bestPlus  = Math.Max(bestPlus,  dp[t - 1, j] + a[j]);

                long overwrite = Math.Max(bestMinus + a[j], bestPlus - a[j]);

                // dp[t][j+1] = max(not ending segment here, or ending here)
                dp[t, j + 1] = Math.Max(dp[t, j], overwrite);
            }

            ans = Math.Max(ans, dp[t, n]);  // because "≤ k" partitions allowed
        }

        return ans;
    }
}