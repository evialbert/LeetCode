class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        a = len(nums)
        count = {}
        for i in nums:
            if i in count:
                calculation = sum(nums) - i
                total = a * (a + 1) // 2
                return [i, total - calculation]
            else:
                count[i] = 1