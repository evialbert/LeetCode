class Solution:
    def isPrime(self, num):
        if num<2:
            return False
        i = 2
        while(i*i<=num):
            if num%i==0:
                return False
            i += 1 
        return True
    def sumOfPrimesInRange(self, n: int) -> int:
        revnum = 0
        num = n
        while(num):
            revnum = revnum*10 + num%10
            num = num//10
        
        sum_ = 0
        for i in range(min(revnum, n), max(revnum, n)+1):
            if self.isPrime(i):
                sum_ = sum_ + i
        return sum_