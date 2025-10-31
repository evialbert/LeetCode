class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        nums.sort()
        res = []

        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                res.append(nums[i])

        return res