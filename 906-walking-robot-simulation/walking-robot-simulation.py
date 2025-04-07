class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        mx=0
        x,y=0,0
        d=(0,1)
        right={(0,1):(1,0),(1,0):(0,-1),(0,-1):(-1,0),(-1,0):(0,1)}
        left={right[i]:i for i in right}
        obstacles=set(map(tuple,obstacles))
        for command in commands:
            if command==-1: d=right[d]
            elif command==-2: d=left[d]
            else:
                for i in range(command):
                    if (x+d[0],y+d[1]) not in obstacles: x,y=x+d[0],y+d[1]
                    else: break
            mx=max(mx,x*x+y*y)
        return mx