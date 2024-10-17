class Solution:
    def maximumSwap(self, num: int) -> int:
    
        num = list(str(num))
        ans = num[:]

        for i, p in enumerate(num):
            for j, q in enumerate(num[i+1:], start = i+1):
                if p < q:
                    n = num[:]
                    n[i], n[j] = q, p
                    if n > ans: ans = n

        return int(''.join(ans))