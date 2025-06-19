class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        n=len(nums)
        count=1
        m=nums[0]
        for i in range(1,n):
            if nums[i]-m >k:
                count+=1
                m=nums[i] 
        return count

        