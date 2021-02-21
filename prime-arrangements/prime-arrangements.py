class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def is_prime(n):
		# avoid of using heavy math functions
            if n < 2: return False
            i = 1
            while i*i <= n:
                if i != 1 and n%i == 0:return False
                i += 1
            return True
        primes = sum(is_prime(i) for i in range(1,n+1))
        def factor(n):
            if n < 2: return 1
            else: return n*factor(n-1)
        return (factor(primes)*factor(n-primes))%(10**9+7)