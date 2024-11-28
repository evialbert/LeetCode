class Pair{
    int cost, x, y;
    Pair(int cost, int x, int y){
        this.cost=cost;
        this.x=x;
        this.y=y;
    }
}
class Solution {
    public int minimumObstacles(int[][] grid) {
        PriorityQueue<Pair> pq=new PriorityQueue<>((a, b)-> a.cost-b.cost);
        int n=grid.length, m=grid[0].length;
        boolean[][] vis=new boolean[n][m];
        vis[0][0]=true;
        pq.add(new Pair(grid[0][0], 0, 0));
        while(!pq.isEmpty()){
            Pair pair=pq.poll();
            int xx=pair.x;
            int yy=pair.y;
            if(xx==n-1 && yy==m-1)return pair.cost;
            if(xx-1>=0 && !vis[xx-1][yy]){
                pq.add(new Pair(pair.cost+grid[xx-1][yy], xx-1, yy));
                vis[xx-1][yy]=true;
            }
            if(yy-1>=0 && !vis[xx][yy-1]){
                pq.add(new Pair(pair.cost+grid[xx][yy-1], xx, yy-1));
                vis[xx][yy-1]=true;
            }

            if(xx+1<n && !vis[xx+1][yy]){
                pq.add(new Pair(pair.cost+grid[xx+1][yy], xx+1, yy));
                vis[xx+1][yy]=true;
            }
             if(yy+1<m && !vis[xx][yy+1]){
                pq.add(new Pair(pair.cost+grid[xx][yy+1], xx, yy+1));
                vis[xx][yy+1]=true;
            }
            
        }
        return -1;
    }
}