class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        searchW={x:True for x in nums}
        res=0
        for n in nums:
            if searchW[n]:
                lc=rc=0
                l=r=n
                searchW[n]=False
                while l-1 in searchW:
                    searchW[l-1]=False
                    l-=1
                    lc+=1
                while r+1 in searchW:
                    searchW[r+1]=False
                    r+=1
                    rc+=1
                res=max(res,lc+rc+1)
        return res