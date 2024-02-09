class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[1])
        points.sort(key=lambda x:-x[0])
        ans=0
        for i in range(len(points)-1):
            lx=points[i][0]
            ly=points[i][1]
            fl=0
            for j in range(i+1,len(points)):
                if(points[j][1]<points[i][1]):
                    continue
                if(fl==1 and ly==points[j][1]):
                    continue
                if(fl==0 and points[j][1]<ly):
                    continue
                if(fl==0):
                    ly=max(ly,points[j][1])
                else:
                    ly=min(ly,points[j][1])
                fl=1
                
                if(points[j][1]==ly and ly>=points[i][1]):
                    ans+=1
        return ans