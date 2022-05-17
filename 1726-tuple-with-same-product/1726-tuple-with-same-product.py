class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        k=Counter()
        for i in range(len(nums)):
            for j in range(i):
                k[nums[i]*nums[j]]+=1
        t=0
        for i in k.values():
            t+=i*(i-1)*4
        return t