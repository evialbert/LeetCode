class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        arr_sum = sum(nums) % p
        if arr_sum == 0 : return 0
        n = len(nums)
        ans = n
        rem_map = {0:-1}
        curr_sum = 0
        for i in range(n):
            curr_sum = (curr_sum + nums[i]) % p
            needed = (curr_sum - arr_sum ) % p
            if needed in rem_map:
                ans = min(ans,i-rem_map[needed])
            rem_map[curr_sum] = i
        return ans if ans != n else -1