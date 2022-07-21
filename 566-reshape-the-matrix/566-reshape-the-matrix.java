class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int[][] newmat = new int[r][c];
        if(r*c!=mat.length*mat[0].length)
            return mat;
        int tempr = 0;
        int tempc = 0;
        for(int i=0;i<mat.length;i++)
        {
            for(int j=0;j<mat[0].length;j++)
            {
                newmat[tempr][tempc++]=mat[i][j];
                if(tempc==c)
                {
                    tempc = 0;
                    tempr++;
                }
            }
        }
        return newmat;
    }
}