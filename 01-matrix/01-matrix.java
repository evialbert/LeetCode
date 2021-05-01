class Solution {
    public class Pair{
        int row;
        int col;
        int dist;
        Pair(int row,int col,int dist){
            this.row=row;
            this.col=col;
            this.dist=dist;
        }
    }
    public int[][] updateMatrix(int[][] matrix) {
        Queue<Pair>que=new LinkedList<>();
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    que.add(new Pair(i,j,0));
                }
            }
        }
        int dir[][]={{0,1},{1,0},{0,-1},{-1,0}};
        int [][]ans=new int[matrix.length][matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                ans[i][j]=-1;
            }
        }
        while(!que.isEmpty()){
            Pair rem=que.poll();
            ans[rem.row][rem.col]=rem.dist;
            for(int i=0;i<4;i++){
                int x=rem.row+dir[i][0];
                int y=rem.col+dir[i][1];
                if(isValid(matrix,ans,x,y)){
                    que.add(new Pair(x,y,rem.dist+1));
                    matrix[x][y]=0;
                }
            }
            
        }
        return ans;
    }
    public boolean isValid(int [][]matrix,int[][]ans,int x,int y){
        if(x<0|| y<0|| x>=ans.length|| y>=ans[0].length || ans[x][y]!=-1|| matrix[x][y]==0){
            return false;
        }
        return true;
    }
}