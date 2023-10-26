class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7
        arr.sort()

        location = {val: i for i, val in enumerate(arr)}
        visited = {}
        def dp(index):
            if index in visited:
                return visited[index]
            value = arr[index]
            ways = 1
            for factor1 in arr[:index]:
                factor2 = value // factor1
                if value % factor1 == 0 and factor2 in location:
                    ways += dp(location[factor1]) * dp(location[factor2])
            visited[index] = ways % MOD
            return visited[index]
        
        res = 0
        for i in range(len(arr)):
            res += dp(i)
        return res % MOD