class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        prime=[True]*1001
        prime[0]=prime[1]=False
        for x in range(2,1001):
            if prime[x]:
                for i in range(x*x,1001,x):
                    prime[i]=False


        prev=0
        for x in nums:
            if prev>=x:
                return False

            for p in range(x-1,-1,-1):
                if prime[p] and x-p>prev:
                    break

            prev=x-p

        return True                            
        
        