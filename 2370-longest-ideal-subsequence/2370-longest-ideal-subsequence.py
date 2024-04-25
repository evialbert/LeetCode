class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n=len(s)
        best=[0]*26
        orda=ord('a')
        nums=list(ord(a)-orda for a in s)
        best[nums[0]]=1
        for i in range(1,n):
            best[nums[i]]+=1
            for j in range(26):
                if abs(j-nums[i])<=k and j!=nums[i]:
                    best[nums[i]]=max(best[j]+1,best[nums[i]])
        return max(best)        