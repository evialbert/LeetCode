class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int castle[][]=new int[m][n];
        for(int guard[]:guards){
            castle[guard[0]][guard[1]]=1;
        }
        for(int wall[]:walls){
            castle[wall[0]][wall[1]]=2;
        }
        for(int guard[]:guards){
            dfs(castle, guard[0]-1, guard[1], m, n, 1);
            dfs(castle, guard[0], guard[1]+1, m, n, 2);
            dfs(castle, guard[0]+1, guard[1], m, n, 3);
            dfs(castle, guard[0], guard[1]-1, m, n, 4);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(castle[i][j]==0){
                    count++;
                }
            }
        }
        return count;
        
    }
    public void dfs(int castle[][], int i, int j, int m, int n, int dir){
        if(i<0||j<0||i>=m||j>=n||castle[i][j]==2||castle[i][j]==1){
            return;
        }
        castle[i][j]=3;
        if(dir==1){
            dfs(castle, i-1, j, m, n, 1);
        }
        else if(dir==2){
            dfs(castle, i, j+1, m, n, 2);
        }
        else if(dir==3){
            dfs(castle, i+1, j, m, n, 3);
        }
        else{
            dfs(castle, i, j-1, m, n, 4);
        }
    }
}