class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.res = []
        def dfs(nums,temp,i):
            self.res.append(temp[:])
            for i in range(i,len(nums)):
                temp.append(nums[i])
                dfs(nums,temp,i+1)
                temp.pop()
                
        dfs(nums,[],0)
        return self.res