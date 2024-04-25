class Solution
{
    long long pie(vector<int> &coins, long long x)
    {
        int m = coins.size();
        int nn = (1 << m);
        long long cnt = 0;
        for (int i = 1; i < nn; i++)
        {
            long long lcmm = 1;
            for (int j = 0; j < m; j++)
            {
                if (i & (1 << j))
                {
                    lcmm = lcm(lcmm, coins[j]);
                }
            }
            if (__builtin_popcount(i) & 1)
                cnt += x / lcmm;
            else
                cnt -= x / lcmm;
        }
        return cnt;
    }

public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        long long kk = k;
        long long l = 1, r = 1e11, ans = 0;
        while (l <= r)
        {
            long long m = l + (r - l) / 2;
            long long cnt = 0;
            cnt = pie(coins, m);
            if (cnt < kk)
                l = m + 1;
            else
            {
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
};