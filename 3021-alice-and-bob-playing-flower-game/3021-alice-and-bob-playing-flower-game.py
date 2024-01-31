class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        clockOdd = n // 2 if n % 2 == 0 else n // 2 + 1
        clockEven = n // 2
        antiOdd = m // 2 if m % 2 == 0 else m // 2 + 1
        antiEven = m // 2
        return clockOdd * antiEven + clockEven * antiOdd