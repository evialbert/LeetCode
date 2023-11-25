class Solution:
    def minCost(self, C, T):
        cmax, csum, ans = T[0], T[0], 0
        for i in range(1, len(C)):
            if C[i] == C[i-1]:
                csum += T[i]
                cmax = max(cmax, T[i])
            else:
                ans += csum - cmax
                csum, cmax = T[i], T[i]
        return ans + csum - cmax