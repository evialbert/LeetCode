class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)

        m = max(nums) + 1
        spf = list(range(m))
        for i in range(2, int(m ** 0.5) + 1):
            if spf[i] == i:
                for j in range(i * i, m, i):
                    if spf[j] == j:
                        spf[j] = i

        scores = [0] * n
        for i, x in enumerate(nums):
            count = 0
            while x > 1:
                count += 1
                p = spf[x]
                while x % p == 0:
                    x //= p
            scores[i] = count

        stack = []
        right = [0] * n
        for i in range(n):
            while stack and scores[stack[-1]] < scores[i]:
                right[stack.pop()] = i
            stack.append(i)
        
        while stack:
            right[stack.pop()] = n
        
        left = [0] * n
        for i in reversed(range(n)):
            while stack and scores[stack[-1]] <= scores[i]:
                left[stack.pop()] = i
            stack.append(i)
        
        while stack:
            left[stack.pop()] = -1

        count = [(i - l) * (r - i) 
                 for i, (l, r) in enumerate(zip(left, right))]
        
        res = 1
        mod = 10 ** 9 + 7
        for i in sorted(range(n), key=lambda i: -nums[i]):
            res = (res * pow(nums[i], min(k, count[i]), mod)) % mod
            k = max(0, k - count[i])
            if k == 0: break

        return res