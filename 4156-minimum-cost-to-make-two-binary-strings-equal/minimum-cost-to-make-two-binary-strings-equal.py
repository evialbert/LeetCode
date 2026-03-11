class Solution:
    def minimumCost(self, s: str, t: str, flipCost: int, swapCost: int, crossCost: int) -> int:
        n_0_1 = 0 # number of "01" pairs
        n_1_0 = 0 # number of "10" pairs
        
        for i in range(len(s)):
            if s[i] == '0' and t[i] == '1':
                n_0_1 += 1
            elif s[i] == '1' and t[i] == '0':
                n_1_0 += 1

        res = 0
        # STAGE 1
        # method 1: flip min(n_0_1, n_1_0) times
        # method 2: swap min(n_0_1, n_1_0) times
        p = min(n_0_1, n_1_0)
        res += min(p * flipCost * 2, p * swapCost)
        
        # STAGE 2
        # after either one of above methods, it will remains 
        # - abs(n_0_1 - n_1_0) of "01" pairs or "10" pairs left
        # method 1: flip remaining abs(n_0_1 - n_1_0) times
        # method 2: cross swap remaining abs(n_0_1 - n_1_0) times and swaps
        #  and if still has remaining odds left should adding one more flipCost
        p = abs(n_0_1 - n_1_0)
        method1 = p * flipCost
        method2 = (p // 2) * crossCost + (p // 2) * swapCost + (p % 2) * flipCost
        res += min(method1, method2)
        
        
        return res