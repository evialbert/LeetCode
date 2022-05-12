class Solution {
    public int[] constructDistancedSequence(int n) {
        int[] res = new int[1 + 2 * (n-1)];
        Arrays.fill(res, -1);
        boolean[] usednumber = new boolean[n+1];
        dfs(res, 0,usednumber, n);
        return res;
    }
    
    public boolean dfs(int[] res, int pos,boolean[] used, int n)
    {
        if(pos >= n)
        {
            return true;
        }
        
        int respos = -1;
        for(int i = 0; i < res.length; i++)
        {
            if(res[i]==-1)
            {
                respos = i;
                break;
            }
        }
        
        for(int i = n; i >=1; i--)
        {
            if(!used[i])
            {
                if(i>1 && respos + i < res.length && res[respos+i]==-1){
                    res[respos] = i;
                    res[respos+i] = i;
                }
                else if(i==1)
                {
                    res[respos] = 1;
                }
                else
                {
                    continue;
                }
                
                used[i] = true;
                if(dfs(res, pos+1, used, n))return true;
                used[i] = false;
                
                if(i>1){
                    res[respos] = -1;
                    res[respos+i] = -1;
                }
                else if(i==1)
                {
                    res[respos] = -1;
                }
            }
        }
        
        return false;
    }
}