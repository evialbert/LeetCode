class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:

        arr2.sort()

        @cache
        def dfs(i, prev_num):

            if i >= len(arr1):
                return 0

            cost = float("inf")

            if arr1[i] > prev_num:
                cost = dfs(i + 1, arr1[i])
            
            idx = bisect.bisect(arr2, prev_num)
            if idx < len(arr2):
                cost = min(cost, 1 + dfs(i + 1, arr2[idx]))
            
            return cost
        
        ans = dfs(0, -1)
        return ans if ans < float("inf") else -1