class Solution:
    def maxGoodNumber(self, nums: List[int]) -> int:
        
        res = 0
        for n in itertools.permutations(nums):
            num1 = bin(n[0])[2:]
            num2 = bin(n[1])[2:]
            num3 = bin(n[2])[2:]

            res = max(res, int(num1 + num2 + num3, 2))

        return res