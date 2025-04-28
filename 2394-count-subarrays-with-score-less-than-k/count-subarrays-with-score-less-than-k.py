class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        count = 0
        cur_sum = 0
        left = 0
        for right in range(len(nums)):
            cur_sum+=nums[right]
            while left<=right and cur_sum*(right-left+1)>=k:
                cur_sum-=nums[left]
                left+=1
            count+=right-left+1
        return count
                