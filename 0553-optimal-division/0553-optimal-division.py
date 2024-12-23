class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if len(nums)==1: 
            return str(nums[0])
        if len(nums)==2:
            return str(nums[0])+"/"+str(nums[1])
        res =""
        for num in nums:
            if res =="":
                res += str(num)+"/("
                continue
            res += str(num)+"/"
        return res[0:-1:]+")"
            
