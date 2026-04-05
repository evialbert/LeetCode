class Solution:
    def isDigitorialPermutation(self, n: int) -> bool:

        fact = [1] * 10
        for i in range(1, 10):
            fact[i] = fact[i - 1] * i

        val = sum(fact[int(d)] for d in str(n))

        return Counter(str(n)) == Counter(str(val))