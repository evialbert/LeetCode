class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        self.nums = nums
        self.len_n = len(nums)
        return self.dfs(0, target)
    
    @cache
    def dfs(self, idx, target):
        if idx == self.len_n:
            if target == 0:
                return 1
            return 0
        
        cnt = 0
        for sign in [-1, 1]:
            cnt += self.dfs(idx + 1, target - self.nums[idx] * sign)
        return cnt