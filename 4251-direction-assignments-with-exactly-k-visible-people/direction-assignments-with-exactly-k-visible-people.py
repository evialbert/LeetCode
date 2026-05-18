class Solution:
    def __init__(self):
        self.mod = int(1e9+7)

    def pow(self,a,b):
        res=1
        while b:
            if b%2:
                res = res*a%self.mod
            a = a*a%self.mod
            b>>=1
        return res%self.mod
    
    def inv_mod(self,b):
        return self.pow(b,self.mod-2) 

    def compute_factorials(self,n):
        factorial = [1]
        for i in range(1,n+1):
            factorial.append(factorial[-1]*i%self.mod)
        return factorial[n]%self.mod
    
    def nCr(self,n,k):
        if k<0 or k>n:
            return 0
        n_fact = self.compute_factorials(n)
        b_fact = self.compute_factorials(k)*self.compute_factorials(n-k)%self.mod
        return n_fact*self.inv_mod(b_fact)%self.mod
        
    def countVisiblePeople(self, n: int, pos: int, k: int) -> int:
         return self.nCr(n-1,k)*2%self.mod
        