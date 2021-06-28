class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        boolean[] rec = new boolean[graph.length];
        boolean[] vis = new boolean[graph.length];
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < graph.length; i++) 
        {
            if(!hasCycle(graph, i, vis, rec))
                res.add(i);
        }
        return res;
    }
    private boolean hasCycle(int[][] graph, int i, boolean[] vis, boolean[] rec) {
        
        if (rec[i]) 
            return true;
        if (vis[i]) 
            return false;
        vis[i]=true;
        rec[i] = true;
        for (int next : graph[i]) 
        {
            if(hasCycle(graph, next, vis, rec)) 
                return true;
        }
        rec[i] = false;
        return false;
    }
}