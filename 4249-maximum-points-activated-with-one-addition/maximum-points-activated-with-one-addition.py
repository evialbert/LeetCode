class Solution:
    def maxActivated(self, points: list[list[int]]) -> int:
        graph1,graph2=defaultdict(list),defaultdict(list)
        n,seen1,seen2=len(points),set(),set()
        for i,(x,y) in enumerate(points):
            graph1[x].append(i)
            graph2[y].append(i)
        arr=[]
        def dfs(x,y,p):
            nonlocal cnt
            cnt+=1
            if p==0:
                if x in seen1: return
                seen1.add(x)
                for i in graph1[x]:
                    xi,yi=points[i]
                    dfs(xi,yi,p^1)
            else:
                if y in seen2: return
                seen2.add(y)
                for i in graph2[y]:
                    xi,yi=points[i]
                    dfs(xi,yi,p^1)
        for i in range(n):
            x,y=points[i]
            cnt=0
            dfs(x,y,0)
            if cnt>0: arr.append(cnt//2)
        arr.sort()
        if len(arr)==1: return arr[0]+1
        return arr[-1]+arr[-2]+1
            
            