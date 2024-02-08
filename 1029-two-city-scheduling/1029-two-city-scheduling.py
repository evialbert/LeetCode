class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:

        l = sorted(costs, key = lambda x : x[0]-x[1])
        n = len(costs)//2
        total = 0
        for i in range(n):
            total += l[i][0]+l[i+n][1]
        return total