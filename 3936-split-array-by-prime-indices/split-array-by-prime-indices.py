class Solution:
    def splitArray(self, nums: list[int]) -> int:
        n = len(nums)
        primes = [False, False] + [True] * (n-2)
        p = 2
        while p**2 < n:
            if primes[p]:
                for q in range(p**2, n, p):
                    primes[q] = False
            p += 1
        sumA = sum(nums[i] for i in range(n) if primes[i])
        sumB = sum(nums) - sumA
        return abs(sumA - sumB)