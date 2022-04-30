class Solution:
    def stoneGameVI(self, av: List[int], bv: List[int]) -> int:
        ax=0;bx=0;f=0
        for v in sorted([i for i in range(len(av))],key=lambda z:-(av[z]+bv[z])):
            if f==0:ax+=av[v];f=1
            else:bx+=bv[v];f=0
        if ax>bx:return 1
        elif bx>ax:return -1
        return 0