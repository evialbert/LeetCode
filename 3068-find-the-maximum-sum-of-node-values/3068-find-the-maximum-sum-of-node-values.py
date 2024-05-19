class Solution:
    def maximumValueSum(self, nums: List[int], k: int, 
                              edges: List[List[int]]) -> int:

        dif = sorted(map(lambda x: x - (x^k), nums)) 
        
        return sum(nums) - sum(filter(lambda x: x < 0, 
                         map(sum, zip(dif[::2],dif[1::2]))))