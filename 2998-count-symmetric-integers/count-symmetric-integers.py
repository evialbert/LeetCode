class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        def sumi(s):
            numbers = [int(char) for char in s]
            return sum(numbers)

        def func(num):
            s=str(num)
            n=len(s)
            if n%2!=0:
                return False

            if sumi(s[:n//2])==sumi(s[n//2:]):
                return True
            return False

        cnt=0
        for i in range(low,high+1):
            if func(i):
                cnt+=1
        return cnt