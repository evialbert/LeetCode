class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)
        if n==0 and nums[0]==0:
            return 0
        i=0
        c=0
        t=0
       
        while i<n:
            if nums[i]==0:
                i+=1
            else:
                c+=1
              
                i+=1
                
        for ele in nums:
            if ele<c and ele!=0:
                c-=1
        for ele in nums:
            if ele>=c:
                t+=1



        if c!=0 and t==c:
            return c   
        return -1