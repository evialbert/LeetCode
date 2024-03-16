class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)
        maxLen = 0
        hashMap = {}
        for i in range(n):
            if nums[i] == 0:
                count -= 1
            else:
                count += 1
            if count == 0:
                maxLen = i + 1
            if count in hashMap:
                maxLen = max(maxLen, i - hashMap[count])
            else:
                hashMap[count] = i
        return maxLen