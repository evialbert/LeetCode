class Solution:
    def getGoodIndices(self, v: List[List[int]], target: int) -> List[int]:
        
        def calc(a, n, m):
            
            if n == 0:
                return 1
            if n == 1:
                return a%m
            
            temp = calc(a, n//2, m)%m
            
            temp = temp*temp
            
            if n%2 == 1:
                temp = temp*a
            
            return temp%m
        ans = []
        
        for i in range(len(v)):
            temp = calc(v[i][0], v[i][1], 10)
            temp = calc(temp, v[i][2], v[i][3])
            
            if temp == target:
                ans.append(i)
        
        return ans