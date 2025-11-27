public class Solution
{
    public long MaxSubarraySum(int[] nums, int k)
    {
        long INF = long.MaxValue;
        long[] minPrefix = new long[k];

        for (int i = 0; i < k; i++)
            minPrefix[i] = INF;

        minPrefix[0] = 0;

        long prefix = 0;
        long answer = long.MinValue;

        for (int i = 0; i < nums.Length; i++)
        {
            prefix += nums[i];
            int mod = (i + 1) % k;

            if (minPrefix[mod] != INF)
                answer = Math.Max(answer, prefix - minPrefix[mod]);

            if (prefix < minPrefix[mod])
                minPrefix[mod] = prefix;
        }

        return answer;
    }
}