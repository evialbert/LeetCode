class Solution {
    List<Integer>[] graph;
    public int maximumDetonation(int[][] bombs) {
        int len =  bombs.length;
        graph = new ArrayList[len];
        for(int i = 0; i < len; i++)
            graph[i] = new ArrayList<Integer>();
        
        for(int i = 0; i < len; i++)
        {
            long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            
            for(int j = 0; j < len; j++)
            {
                if(i != j)
                {
                    long x2 = bombs[j][0], y2 = bombs[j][1];
                    if(withinRange(x1, y1, r1, x2, y2))
                        graph[i].add(j);
                }
            }
        }
        int max = 1;
        for(int idx = 0; idx < len; idx++)
            max = Math.max(max, dfs(idx, new boolean[len]));
        
        return max;
    }
    
    private boolean withinRange(long x1, long y1, long r1, long x2, long y2)
    {
        long eucledianX = (x1 - x2)*(x1 - x2);
        long eucledianY = (y1 - y2)*(y1 - y2);
        long radius = r1*r1;
        
        return ((eucledianX + eucledianY) <= (radius));
    }
    
    private int dfs(int bomb, boolean[] visited)
    {
        visited[bomb] = true;
        int ans = 1;
        for(int neighbour: graph[bomb])
            if(!visited[neighbour])
                ans += dfs(neighbour, visited);
        
        return ans;
    }
}