class Solution:
    def minGenerations(self, points: List[List[int]], tar: List[int]) -> int:
        ans=0
        if tar in points:
            return 0
        nt=str(tar[0])+','+str(tar[1])+','+str(tar[2])
        d={}
        f=0
        while True:
            l=[]
            n=len(points)
            ans += 1
            for i in range(n):
                p=points[i]
                for j in range(i,n):
                    t=points[j]
                    x=(p[0]+t[0])//2
                    y=(p[1]+t[1])//2
                    z=(p[2]+t[2])//2
                    k=str(x)+','+str(y)+','+str(z)
                    if nt==k:
                        return ans
                    if d.get(k,-1)==-1:
                        l.append([x,y,z])
                        d[k]=True
            if l==[]:
                return -1
            for u in l:
                points.append(u)