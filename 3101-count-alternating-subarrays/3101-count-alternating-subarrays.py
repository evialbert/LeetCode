class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        
        res , cnt = 0 , 0
        val = None
        
        for i in nums:
            
            if val != i:
                cnt += 1
            else:
                cnt = 1
            val = i
            res += cnt
        
        return res