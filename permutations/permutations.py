class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        nums = list(sorted(nums))
        visited = set()
        self.helper(nums, visited, [], result)
        
        return result
    
    def helper(self, nums, visited, subset, result):

        if len(subset) == len(nums):
            result.append(list(subset))        
        
        for i in range(0, len(nums)):
            if (nums[i] in visited):
                continue
                
            subset.append(nums[i])
            visited.add(nums[i])
            
            self.helper(nums, visited, subset, result)
            
            visited.remove(nums[i])
            subset.pop()