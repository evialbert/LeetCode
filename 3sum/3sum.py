class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        
        result = []
        
        for left in range(len(nums)):
            
            if left > 0 and nums[left-1] == nums[left]:
                continue
            
            mid, right = left+1, len(nums) - 1
            
            while mid < right :
                
                if nums[left] + nums[mid] + nums[right] == 0:
                    result.append([nums[left], nums[mid], nums[right]])
                    mid += 1
                    right -= 1
                    
                    # Skip all the duplicate elements
                    while mid < right and nums[mid-1] == nums[mid]:
                        mid += 1
                    
                    # Skip all the duplicate elements
                    while mid < right and nums[right] == nums[right+1]:
                        right -= 1
                        
                elif nums[left] + nums[mid] + nums[right] > 0:
                    right -= 1
                else:
                    mid += 1
        
        return result