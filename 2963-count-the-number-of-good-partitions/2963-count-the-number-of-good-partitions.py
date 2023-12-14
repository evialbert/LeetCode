class Solution:
    def numberOfGoodPartitions(self, nums: List[int]) -> int:
        endIndex = {}
        for i,num in enumerate(nums):
            endIndex[num] = i
        groups = 0
        rightIndex = 0
        for i,num in enumerate(nums):
            rightIndex = max(rightIndex,endIndex[num])
            if rightIndex==i:
                rightIndex = i+1
                groups+=1
        MOD = 10**9+7
        ans = 1
        
        for i in range(groups-1):
            ans = ((ans%MOD)*2)%MOD
        
        return ans