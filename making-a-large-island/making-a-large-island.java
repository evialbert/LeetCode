class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    public int largestIsland(int[][] grid) {
        int islandId = 1;
        Map<Integer,Integer> islandMap = new HashMap();
        Set<Integer> visited = new HashSet();
        int l =grid.length;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(grid[i][j]==1 && !visited.contains(i*l+j)){
                    Set<Integer> curVisited = new HashSet();
                    dfs(i,j,curVisited,visited,grid,l,islandId);
                    if(curVisited.size()==l*l)
                        return curVisited.size();
                    islandMap.put(islandId,curVisited.size());
                    islandId++;
                }
            }
        }
        
        int max=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(grid[i][j]==0){
                  int count = 1;
                    Set<Integer> set = new HashSet();
                  for(int[] d : dir) {
                        int x = d[0]+i;
                        int y = d[1]+j;
                        if(x<l && y<l  && x>=0 && y>=0 && grid[x][y]!=0){
                            if(!set.contains(grid[x][y])){
                                count+=islandMap.get(grid[x][y]);
                                set.add(grid[x][y]);
                            }
                        }
                    }
                    max=Math.max(max,count);
                }
            }
        }
        return max;
    }
    
    void dfs(int i,int j,Set<Integer> curVisited,Set<Integer> visited,int[][] grid,int l,int islandId){
        if(i==l || j==l || i<0 || j<0 || grid[i][j]==0 || visited.contains(i*l+j))
            return;
        visited.add(i*l+j);
        curVisited.add(i*l+j);
        grid[i][j]=islandId;
        for(int[] d : dir) {
            dfs(d[0]+i,d[1]+j,curVisited,visited,grid,l,islandId);
        }
    }
}