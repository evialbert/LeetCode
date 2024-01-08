class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        cost=0
        while(any(x!=0 for x in nums) or k!=0):
            counts=0
            for i in range(len(nums)):
                if nums[i]&1==1:
                    counts+=1
                nums[i]=nums[i]>>1
            if counts&1!=k&1:
                cost+=1
            k=k>>1
        return cost