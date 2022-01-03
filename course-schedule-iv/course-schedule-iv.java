class Solution {
    Map<Integer, List<Integer>> adjMap;
    boolean[][] connectivity;
    
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] reqs, int[][] queries) {
        
        int n = numCourses;
        this.adjMap = new HashMap<Integer, List<Integer>>();
        this.connectivity = new boolean[n][n];
        
        for (int[] req : reqs) {
            adjMap.putIfAbsent(req[0], new ArrayList<Integer>());
            adjMap.get(req[0]).add(req[1]);
        }
        
        //Start DFS from all nodes to mark all the nodes reachable from it
        for (int i=0; i<n; i++) {
            connectivity[i][i] = true;
            dfs(i, i);
        }
        
        List<Boolean> ans = new ArrayList<Boolean>();
        for (int i=0; i<queries.length; i++) {
            ans.add(connectivity[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
    
    void dfs(int node, int root) {
        for (Integer neigh : adjMap.getOrDefault(node, Collections.emptyList())) {
            if (!connectivity[root][neigh]) {
                connectivity[root][neigh] = true;
                dfs(neigh, root);
            }
        }
    }
}