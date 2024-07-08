class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        nums=[]
        for i in range(1,n+1):
            nums.append(i)
        j=0
        while len(nums)!=1:
           j=(j+k-1)%len(nums)
           nums.remove(nums[j])
        return nums[0]    