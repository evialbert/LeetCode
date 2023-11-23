class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        n=len(nums)
        def good(left,right):
            k=list(sorted(nums[left:right+1]))
            if len(k)==1:
                return True
            delta=k[1]-k[0]
            for i,j in zip(k,k[1:]):
                if (abs(i-j))!=delta:
                    return False
            return True
        ans=[]
        for left,right in zip(l,r):
            ans+=[good(left,right)]
        return ans                    