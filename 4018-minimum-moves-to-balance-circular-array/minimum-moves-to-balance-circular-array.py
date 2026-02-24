class Solution:
    def minMoves(self, balance: List[int]) -> int:
        n = len(balance)
        t= False
        for x in range(len(balance)):
            if balance[x] <0 :
                t = True
                break

        if  t== False:
            return 0
        i = x
        if x-1>=0 and x+ 1 <n:
            j = x-1
            i = x+1
        elif x-1 <0:
            i = min(x+1, n-1)
            j = max(0,n-1)
        else:
            i = 0
            j= max(0,x-1)
            
        ans = 0
        d  =1
        while balance[x] < 0 and i != j:
            
            if i == x:
                total =  balance[j]
            elif j == x:
                total =  balance[i]
            else:
                total = balance[j]+ balance[i]
            if balance[x] * -1>= total:
                balance[x] = balance[x]+ total
                ans  = ans +  (balance[j] * d + balance[i] * d)
                balance[j] = 0 
                balance[i] = 0
                i = i+1 
                j = j-1
            elif balance[x] * -1 < total:
                ans = ans +  d * (balance[x] * -1)
                balance[x] = 0
                break   
            
            if i >=n:
                i = 0
            if j < 0:
                j = n-1
            d = d+1
        if balance[x] < 0 and i!=x:
            total = balance[i]

            ans = ans +  d * (balance[x] * -1)
            balance[x] = balance[x]+ total
            
        if balance[x]<0:
            return -1
        return ans
        
        