class Solution:
    def minEnd(self, n: int, x: int) -> int:
        if n == 1:
            return x
        
        zerobits = []
        for i in range(63, -1, -1):
            if not ((1<<i) & x):
                zerobits.append(i)

        additional = 0
        binary = "{0:b}".format(int(n-1))
        z = zerobits[-len(binary):]
        
        for i, j in enumerate(z):
            if binary[i] == '1':
                additional += pow(2, j)
            
        return x + additional