class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        boolean[] visited = new boolean[n];
        int result = 0;
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            List<Integer> list = graph.getOrDefault(edge[0], new ArrayList<>());
            list.add(edge[1]);
            graph.put(edge[0], list);
            List<Integer> list2 = graph.getOrDefault(edge[1], new ArrayList<>());
            list2.add(edge[0]);
            graph.put(edge[1], list2);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<Integer> bfs = new LinkedList<>();
                bfs.add(i);
                int degree = graph.getOrDefault(i, new ArrayList<>()).size();
                boolean doesAllVisitedNodesHasEqualDegree = true;
                int nodeVisited = 0;
                while (!bfs.isEmpty()) {
                    Integer node = bfs.remove();
                    nodeVisited++;
                    List<Integer> next = graph.getOrDefault(node, new ArrayList<>());
                    if (degree != next.size() && doesAllVisitedNodesHasEqualDegree) {
                        doesAllVisitedNodesHasEqualDegree = false;
                    }
                    for (Integer nn : next) {
                        if (!visited[nn]) {
                            visited[nn] = true;
                            bfs.add(nn);
                        }
                    }
                }
                if ((degree == nodeVisited - 1) && doesAllVisitedNodesHasEqualDegree) {
                    result++;
                }
            }
        }
        return result;
    }
}