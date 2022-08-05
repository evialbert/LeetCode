class Solution {
  public int[][] findFarmland(int[][] land) {
    int[][] visited = new int[land.length][land[0].length];
    List<int[]> res = new ArrayList<>();
    for(int i = 0; i < land.length; i++) {
      for(int j = 0; j < land[0].length; j++) {
        if(visited[i][j] != 1 && land[i][j] == 1) {
          int[] end = dfs(land, visited, i, j);
          res.add(new int[]{i, j, end[0], end[1]});
        }
      }
    }
    
    int[][] resArray = new int[res.size()][4];
    for(int i = 0; i < res.size(); i++) {
      resArray[i] = res.get(i);
    }
    
    return resArray;
  }
  
  private int[] dfs(int[][] land, int[][] visited, 
                    int i, int j) {
    if(i == land.length || j == land[0].length 
       || visited[i][j] == 1 
       || land[i][j] == 0) {
      return null;
    }
    
    visited[i][j] = 1;
    
    int[] res = null;
    if(i + 1 < land.length) {
      res = dfs(land, visited, i + 1, j);
    }
    
    if(j + 1 < land[0].length) {
      int[] rightRes = dfs(land, visited, i, j + 1);
      if(res == null) {
        res = rightRes;
      }
    }
    
    if(isEnd(land, i, j)) {
      return new int[]{i, j};
    }
    
    return res;
  }
  
  private boolean isEnd(int[][] land, int i, int j) {
    return (j + 1 == land[0].length || land[i][j+1] == 0) 
      && (i + 1 == land.length || land[i+1][j] == 0);
  }
}