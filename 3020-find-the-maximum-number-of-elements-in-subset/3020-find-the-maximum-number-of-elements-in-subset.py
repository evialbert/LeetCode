class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        m = collections.defaultdict(int)
        for i in nums:
            m[i] += 1
        ans = m[1]
        if m[1]>0 and m[1]%2 == 0:
            ans = m[1]-1
        for i in sorted(nums):
            res = 1
            if i==1:
                continue
            while m[i**2]>0 and m[i]>1:
                res+=2
                m[i]-=2
                i = i**2
            ans = max(ans, res)
        return ans
        