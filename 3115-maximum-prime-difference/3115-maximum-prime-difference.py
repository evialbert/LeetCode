class Solution:
    def maximumPrimeDifference(self, nums: list[int]) -> int:
        # I can't be bothered to implement sieve of eratosthenes
        primes = set([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97])
        for i in range(len(nums)):
            if nums[i] in primes:
                break
        
        for j in range(len(nums)-1, -1, -1):
            if nums[j] in primes:
                break
        return j - i