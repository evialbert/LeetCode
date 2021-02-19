class Solution(object):
    def combinationSum2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def dfs(nums, target, path, res):
            if len(nums) == 0 and target != 0:
                return
            if target == 0:
                res.append(path)
                return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                if nums[i] <= target:
                    dfs(nums[i+1:], target-nums[i], path+[nums[i]], res)               
             
        nums.sort()
        res = []
        dfs(nums, target, [], res)
        return res
