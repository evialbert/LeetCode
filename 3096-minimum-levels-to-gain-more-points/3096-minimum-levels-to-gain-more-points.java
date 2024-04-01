class Solution
{
    public int minimumLevels(int[] p)
    {
        int n = p.length;

        if(p[0]==0)
            p[0] = -1;
        
        for(int i=1; i<n; i++)
            p[i] = p[i-1] + (p[i]==1 ? 1 : -1);

        for(int i=0; i<n-1; i++)
            if(p[i]*2>p[n-1])
                return i+1;

        return -1;
    }
}