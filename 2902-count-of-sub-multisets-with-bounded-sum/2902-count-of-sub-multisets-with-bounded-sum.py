class Solution:
    def countSubMultisets(self, nums: List[int], l: int, r: int) -> int:
        dp = defaultdict(int)
        dp[0] = 1
        counter = Counter(nums)
        for num, count in counter.items():
            for i in range(num):
                total = sum(dp[r-i-num*c] for c in range(1, count+1))
                for n in range(r-i, 0, -num):
                    dp[n] += total
                    total = total - dp[n-num] + dp[n-num*(count+1)]

        res = 0
        for i in range(l, r+1):
            res = (res + dp[i]) % (10**9 + 7)
        return res * (counter[0] + 1) % (10**9 + 7)
