class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int n=rowSum.length;
        int m=colSum.length;
        int i,j;
        int[][] res=new int[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                res[i][j]=Math.min(rowSum[i],colSum[j]);
                rowSum[i]-=res[i][j];
                colSum[j]-=res[i][j];
            }
        }
        return res;
    }
}