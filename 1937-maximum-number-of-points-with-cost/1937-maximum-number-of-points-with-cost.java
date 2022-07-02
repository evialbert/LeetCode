class Solution {
    public long maxPoints(int[][] points) {
        int n=points.length,m=points[0].length;
        long prev[]=new long[m+1];
        long curr[]=new long[m+1];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
                curr[j]=points[i][j]+prev[j];
            for(int j=m-1;j>=0;j--)
            {
                curr[j]=Math.max(curr[j],curr[j+1]-1);
            }
            for(int j=1;j<m;j++)
            {
                curr[j]=Math.max(curr[j],curr[j-1]-1);
            }
            for(int j=0;j<=m;j++)
                prev[j]=curr[j];
        }
        long ans=0;
        for(int j=0;j<m;j++)
        {
            ans=Math.max(curr[j],ans);
        }
        return ans;
    }
}