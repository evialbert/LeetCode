class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        if (n <= 0 || edges == null || edges.length == 0 || hasApple == null || hasApple.size() != n) {
            return 0;
        }
        
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (int[] edge : edges) {
            adjList.putIfAbsent(edge[0], new ArrayList<>());
            adjList.putIfAbsent(edge[1], new ArrayList<>());
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        
        Set<Integer> visited = new HashSet<>();
        return visit(n, hasApple, adjList, visited, 0);
    }
    
    private int visit(int n, List<Boolean> hasApple, Map<Integer, List<Integer>> adjList, Set<Integer> visited, int node) {
        if (visited.contains(node)) {
            return 0;
        }
        visited.add(node); // add visited right away so following recursive call will not visit node again
        
        int childrenCost = 0;
        for (int child : adjList.get(node)) {
            childrenCost += visit(n, hasApple, adjList, visited, child);
        }
        // skip if there is no apple in this entire subtree
        if (childrenCost == 0 && !hasApple.get(node)) {
            return 0;
        }
        // no cost to get to node 0
        if (node == 0) {
            return childrenCost;
        }
        
        return childrenCost + 2;
    }
}