class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        N = len(nums)
        mod = (1 << 61) - 1
        base = 10 ** 5 + 5

        def g(length):
            power = pow(base, length, mod)

            h = 0
            for i in range(length):
                h = (h * base + nums[i]) % mod

            f = defaultdict(int)
            f[h] += 1
            
            for i in range(1, N - length + 1):
                h = (h * base - nums[i - 1] * power + nums[i + length - 1]) % mod
                f[h] += 1

            for v in f.values():
                if v == 1:
                    return True
            return False

        l, r = 1, N
        while l < r:
            m = (l + r) // 2
            if g(m):
                r = m
            else:
                l = m + 1
        return l