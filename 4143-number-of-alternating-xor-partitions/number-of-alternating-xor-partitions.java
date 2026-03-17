class Solution {
       private static final int MOD = 1_000_000_007;

    public int alternatingXOR(int[] nums, int target1, int target2) {
        Map<Long, Integer> memo = new HashMap<>();
        return solve(nums, target1, target2, target1, 1, nums[0], memo);
    }

    private int solve(int[] nums, int target1, int target2,
                      int currentTarget, int index, int value,
                      Map<Long, Integer> memo) {

        // Base case: all elements used
        if (index == nums.length) {
            return value == currentTarget ? 1 : 0;
        }

        // Create a unique key for memoization
        long key = ((long) index << 18) | ((currentTarget == target1 ? 0 : 1) << 17) | value;

        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int ways = 0;

        // Option 1: continue current segment
        ways = (ways + solve(nums, target1, target2, currentTarget, index + 1, value ^ nums[index], memo)) % MOD;

        // Option 2: close segment if XOR matches currentTarget
        if (value == currentTarget) {
            int nextTarget = (currentTarget == target1) ? target2 : target1;
            ways = (ways + solve(nums, target1, target2, nextTarget, index + 1, nums[index], memo)) % MOD;
        }

        memo.put(key, ways);
        return ways;
    }
}