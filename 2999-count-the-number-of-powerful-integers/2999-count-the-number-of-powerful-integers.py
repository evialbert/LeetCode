class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        
        if int(s)>finish:
            return 0
        
        def dfs(index,x,ind=0):

            if index>= len(x)-len(s):
                if ind==0:return 1
                return 1 if int(x[index:])>=int(s) else 0
            
            if (index,ind) in dp:
                return dp[(index,ind)]
            val=0
            if ind==1:
                for i in range(min(limit,int(x[index]))+1):
                    if i==int(x[index]):
                        val+=dfs(index+1,x,1)
                    else:
                        val+=dfs(index+1,x,0)
            else:
                for i in range(limit+1):
                    val+=dfs(index+1,x,0)
            dp[(index,ind)]=val
            return dp[(index,ind)]

        dp={}
        if start-1<int(s):start_val=0
        else:start_val = dfs(0,str(start-1),1)
        dp={}
        if finish<int(s):end_val=0
        else:end_val = dfs(0,str(finish),1)

        return end_val-start_val