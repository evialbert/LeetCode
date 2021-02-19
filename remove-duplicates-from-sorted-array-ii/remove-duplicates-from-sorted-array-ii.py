class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)
        
        if n < 3:
            return n
        
        i , j = 1, 2
        
        while j < n:
            if nums[i-1] != nums[j]:
                i += 1
            
            
            nums[i] = nums[j]
            j+= 1
        
        return i+1