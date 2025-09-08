class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        li = []
        for i in range(1, n//2 +1):
            a = str(i)
            b = str(n - i)
            if '0' not in a and '0' not in b:
                li.append(int(a))
                li.append(int(b))
                return li
        
        