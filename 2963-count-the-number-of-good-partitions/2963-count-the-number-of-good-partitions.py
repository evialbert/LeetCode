class Solution:
    def numberOfGoodPartitions(self, nums: List[int]) -> int:
        a={}
        for i in range(len(nums)):
            a[nums[i]]=i
        def do(st):
            if(st==len(nums)):
                return 0
            end=a[nums[st]]
            p=st
            ans=0
            while(p<end):
                end=max(end,a[nums[p]])
                p+=1
            ans+=1+do(p+1)
            return ans
        return (2**(do(0)-1))%1000000007