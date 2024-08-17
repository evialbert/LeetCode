class NeighborSum {
    int[] adjC={1,0,-1,0};
    int[] adjR={0,1,0,-1};
    int[] adjDr={1,1,-1,-1};
    int[] adjDc={1,-1,-1,1};
    int[][] g;
    public NeighborSum(int[][] grid) {
        g=grid;
    }
    public boolean isValid(int nr, int nc){
        return nr>=0 && nc>=0 && nr<g.length && nc<g[0].length;
    }
    public int adjacentSum(int value) {
        int ii=0;
        int jj=0;
        for(int i=0;i<g.length;i++){
            for(int j=0;j<g[0].length;j++){
                if(g[i][j]==value){
                    ii=i;
                    jj=j;
                    break;
                }
            }
        }
        int sum=0;
        for(int i=0;i<4;i++){
            int nr=ii+adjR[i];
            int nc=jj+adjC[i];
            if(isValid(nr,nc))
            sum+=g[nr][nc];
        }
        return sum;
    }
    
    public int diagonalSum(int value) {
        int ii=0;
        int jj=0;
        for(int i=0;i<g.length;i++){
            for(int j=0;j<g[0].length;j++){
                if(g[i][j]==value){
                    ii=i;
                    jj=j;
                    break;
                }
            }
        }
        int sum=0;
        for(int i=0;i<4;i++){
            int nr=ii+adjDr[i];
            int nc=jj+adjDc[i];
            if(isValid(nr,nc))
            sum+=g[nr][nc];
        }
        return sum;
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum obj = new NeighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */