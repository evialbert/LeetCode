class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        l=len(nums)#length of nums 
        nums.sort()#sort the nums
        if l<2:
            return 0
        if l==2:
            return nums[1]-nums[0]
        m=nums[1]-nums[0]#max gap
        for i in range(l):
            if (i==0) or (nums[i]-nums[i-1]<=m): 
                continue
            else:
                m=nums[i]-nums[i-1]#update m
        return m