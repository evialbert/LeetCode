class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        nums.sort()
        i = 0
        j = 0
        c = 0
        ans = 0
        while j < len(nums):
            m = i + (j-i) // 2
            c += nums[j] - nums[m]
            while c > k and i < m:
                c -= abs(nums[(i + j + 1) // 2] - nums[i])
                i+=1
            ans = max(ans, j - i + 1)
            j+=1
        return ans