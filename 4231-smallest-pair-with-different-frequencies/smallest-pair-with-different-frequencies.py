class Solution:
    def minDistinctFreqPair(self, nums: list[int]) -> list[int]:
        freq=[0]*101
        list.sort(nums)
        for i in nums:
            freq[i]+=1
        sm=nums[0]
        smfreq=freq[sm]
        for i in nums:
            if i!=sm and smfreq!=freq[i]:
                return [sm,i]
        return [-1,-1]