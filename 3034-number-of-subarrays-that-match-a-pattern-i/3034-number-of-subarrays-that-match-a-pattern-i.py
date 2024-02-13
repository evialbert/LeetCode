class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        count = 0
        n = len(nums)
        m = len(pattern)
        
        for i in range(n - m):
            sub_arr = nums[i:i+m+1]
            new_pattern = []
            for j in range(m):
                if sub_arr[j] < sub_arr[j+1]:
                    new_pattern.append(1)
                elif sub_arr[j] == sub_arr[j+1]:
                    new_pattern.append(0)
                elif sub_arr[j] > sub_arr[j+1]:
                    new_pattern.append(-1)
                    
            if new_pattern == pattern:
                count += 1
                
        return count