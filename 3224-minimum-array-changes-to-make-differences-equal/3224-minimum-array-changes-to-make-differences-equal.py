class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        n = len(nums)
        change_count = [n//2]*(k+1)
        extra_count = [0]*(k+2)
        
        for i in range(n//2):
            curr_diff = abs(nums[i] - nums[n - i - 1])
            max_diff = max(nums[i], nums[n - i - 1], k-nums[i], k-nums[n - i - 1])
            change_count[curr_diff] -= 1
            extra_count[max_diff+1] += 1 #add 1 step if X > max_diff
        
        extra_sum = 0
        min_change = math.inf
        for i in range(k+1):
            extra_sum += extra_count[i]
            if min_change > change_count[i]+extra_sum:
                min_change = change_count[i]+extra_sum
        return min_change
 