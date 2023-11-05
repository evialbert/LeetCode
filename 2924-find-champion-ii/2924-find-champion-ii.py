class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        l=[0]*n
        for x,y in edges:
            l[y]+=1
        m=min(l)
        if l.count(m)==1:
            return l.index(m)
        return -1
    
   # Time complexity: O(n)
   # Space complexity: O(n)