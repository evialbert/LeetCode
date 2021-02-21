class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        mini = 0
        temp = 0
        for i in nums:
            temp += i
            if temp<mini:
                mini=temp
        return -mini+1