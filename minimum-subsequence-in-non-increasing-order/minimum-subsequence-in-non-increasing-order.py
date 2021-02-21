class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        new_list=[]
        nums.sort()
        while sum(new_list)<=sum(nums):
            new_list.append(nums.pop()) 
        return new_list