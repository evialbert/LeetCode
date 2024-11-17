class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n=len(nums)
        nums=list(accumulate(nums, operator.add))

        dp=[0]*n
        front, back, Len=0, -1, 10**9
        for r, x in enumerate(nums):
            if x>=k: Len=min(Len, r+1)
            while front<=back and x-nums[dp[front]]>=k:
                Len=min(Len, r-dp[front])
                front+=1
            while front<=back and x<=nums[dp[back]]:
                back-=1
            back+=1
            dp[back]=r
        return Len if Len!=10**9 else -1
        