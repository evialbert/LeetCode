class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count=0
        i=0
        n=len(nums)
        while i<(n-2):
            if nums[i]==0:
                nums[i]=1
                if nums[i+1]==1:
                    nums[i+1]=0
                else:
                    nums[i+1]=1

                if nums[i+2]==1:
                    nums[i+2]=0
                else:
                    nums[i+2]=1
                count+=1
            i+=1
        
        for i in nums:
            if i==0:
                return -1
        return count