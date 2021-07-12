class Solution {
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < N; i++) graph.add(new ArrayList<>());
        for(int i = 0; i < edges.length; i++) {
            graph.get(edges[i][0]).add(edges[i][1]);
            graph.get(edges[i][1]).add(edges[i][0]);
        }
        int[] childPathSums = new int[N];
        int[] childCounts = new int[N];
        int[] parentPathSums = new int[N];
        childPathSum(graph, childPathSums, childCounts, 0, new boolean[N]);
        parentPathSum(graph, childPathSums, childCounts, parentPathSums, 0, new boolean[N]);
        for(int i = 0; i < N; i++) 
            parentPathSums[i] += childPathSums[i];
        return parentPathSums;
    }
    
    /**
    Returns the number of childrens, including itself. Also maintains the child path sum. which is sum of paths for a parent to all of its anscestors.
    **/
    private int childPathSum(List<List<Integer>> graph, int[] childPathSums, int[] childCounts, int node, boolean[] vis) {
        if(vis[node] == true) return 0;
        vis[node] = true;
        int count = 1;
        for(int i = 0; i < graph.get(node).size(); i++) {
            if(vis[graph.get(node).get(i)] == true) continue;
            count += childPathSum(graph, childPathSums, childCounts, graph.get(node).get(i), vis);
            childPathSums[node] += childPathSums[graph.get(node).get(i)];
        }
        childPathSums[node] += count - 1;
        childCounts[node] = count;
        return count;
    }
    
    /**
    Calculates the parent path sum for a node.
    */
    private void parentPathSum(List<List<Integer>> graph, int[] childPathSums, int[] childCounts, int[] parentPathSums, int node, boolean[] vis) {
        if(vis[node] == true) return;
        vis[node] = true;
        for(int i = 0; i < graph.get(node).size(); i++) {
            if(vis[graph.get(node).get(i)] == true) continue;
            int toNode = graph.get(node).get(i);
            parentPathSums[toNode] += (parentPathSums[node] + childPathSums[node] - childPathSums[toNode] - childCounts[toNode]) + (graph.size() - childCounts[toNode]);
            parentPathSum(graph, childPathSums, childCounts, parentPathSums, toNode, vis);
        }
    }
}