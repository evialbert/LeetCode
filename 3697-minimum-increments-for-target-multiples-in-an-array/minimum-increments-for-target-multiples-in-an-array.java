class Solution {

    int numCount, targetCount;
    int[] nums, target;
    long[][] dp;
    long[] lcmPrecomputed;

    public int minimumIncrements(int[] nums, int[] target) {
        this.nums = nums;
        this.target = target;
        this.numCount = nums.length;
        this.targetCount = target.length;
        this.dp = new long[numCount + 1][1 << targetCount + 1];

        for (int i = 0; i < numCount + 1; i++) {
            Arrays.fill(dp[i], -1);
        }

        lcmPrecomputed = new long[1 << targetCount];
        precompute();

        long ans = solve(0, 0);
        return (int) ans;
    }

    public void precompute() {
        int total = 1 << targetCount;
        for (int i = 0; i < total; i++) {
            lcmPrecomputed[i] = 1;
            for (int j = 0; j < targetCount; j++) {
                if ((i & (1 << j)) != 0) {
                    lcmPrecomputed[i] = findLCM(lcmPrecomputed[i], target[j]);
                }
            }
        }
    }

    public long findLCM(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }

    public long solve(int i, int mask) {
        int fullMask = (1 << targetCount) - 1;

        if (mask == fullMask) {
            return 0;
        }
        if (i == numCount) {
            return (long) 1e9;
        }

        if (dp[i][mask] != -1) {
            return dp[i][mask];
        }

        long min = (long) 1e9;

        // skip
        min = Math.min(min, solve(i + 1, mask));

        // take
        int totalSubsets = 1 << targetCount;
        for (int subset = 1; subset < totalSubsets; subset++) {
            long subsetLCM = lcmPrecomputed[subset];
            long nextMultiple = (long) (Math.ceil((nums[i] * 1.0) / subsetLCM) * subsetLCM);
            min = Math.min(min, (nextMultiple - nums[i]) + solve(i + 1, mask | subset));
        }

        return dp[i][mask] = min;
    }
}