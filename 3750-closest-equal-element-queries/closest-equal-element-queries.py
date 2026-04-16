class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:

        mp1 = collections.defaultdict(list)
        mp2 = collections.defaultdict(lambda: defaultdict(int))

        for index, value in enumerate(nums):
            mp1[value].append(index)
            mp2[value][index] = len(mp1[value])-1
          
        ans = []    

        for q in queries:
            L = mp1[nums[q]]
            index = mp2[nums[q]][q]
            x, y = abs(L[index]-L[(index+1) % len(L)]), abs(L[index]-L[(index-1) % len(L)])
            if x == 0 and y == 0:
                ans.append(-1)
            else:    
                ans.append(min(x, y, len(nums)-x, len(nums)-y))
             
        return ans    

        