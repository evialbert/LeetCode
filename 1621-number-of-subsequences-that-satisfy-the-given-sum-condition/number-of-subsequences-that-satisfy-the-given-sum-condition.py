class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        
        n = len(nums)
        nums.sort()

        if 2*nums[-1] < target:
            return 0

        ans = 0
        mod = 10**9 + 7
        prefix = [0] * n

        for i in range(n):
            prefix[i] = (prefix[i-1] + pow(2, i, mod))%mod


        for i in range(n-1, -1, -1):
            idx = bisect.bisect_right(nums, target-nums[i]) - 1

            if idx == -1:
                continue

            if i > idx:
                ans = (ans + prefix[i-1] - (prefix[i-idx-2] if i-idx-2 >=0 else 0) + mod) %mod
            else:
                ans = (ans + ((prefix[i-1] + 1) if i-1 >=0 else 1)) % mod
        
        return ans