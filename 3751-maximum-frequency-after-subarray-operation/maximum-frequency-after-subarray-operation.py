class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        prefix = [0]
        for x in nums: 
            prefix.append(prefix[-1])
            if x == k: prefix[-1] += 1
        ans = 0
        for v in range(1, 51): 
            sk = sv = most = 0 
            for i, x in reversed(list(enumerate(nums))): 
                if x == k: sk += 1
                elif x == v: sv += 1
                most = max(most, sk - sv)
                ans = max(ans, sv + most + prefix[i])
        return ans 