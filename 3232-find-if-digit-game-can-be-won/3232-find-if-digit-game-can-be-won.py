class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        single_sum, double_sum = 0, 0
        for num in nums:
            if num > 9:
                double_sum += num
            else:
                single_sum += num
        return False if double_sum == single_sum else True
