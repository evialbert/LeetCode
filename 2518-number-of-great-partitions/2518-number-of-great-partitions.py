class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        p=10**9+7
        s=sum(nums)
        if s<2*k:
            return 0
        
        @cache
        def ct(i, k1, k2):
            n=nums[i]
            if i==0:
                ans=0
                if n>=k1 and k2==0:
                    ans+=1
                if n>=k2 and k1==0:
                    ans+=1
                return ans
            t1=max(k1-n, 0)
            t2=max(k2-n, 0)
            return (ct(i-1, t1, k2)+ct(i-1, k1, t2))%p
        
        return ct(len(nums)-1, k, k)