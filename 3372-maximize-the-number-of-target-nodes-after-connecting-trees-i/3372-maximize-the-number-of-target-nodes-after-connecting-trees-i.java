class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        Map<Integer, List<Integer>> tree1 = new HashMap<>();
        Map<Integer, List<Integer>> tree2 = new HashMap<>();
        constructGraph(edges1, tree1);
        constructGraph(edges2, tree2);
        int tree1Size = calculateTreeSize(edges1);
        int tree2Size = calculateTreeSize(edges2);
        int[] result = new int[tree1Size];
        for (int i = 0; i < tree1Size; i++) {
            Set<Integer> set = new HashSet<>();
            set.add(i);
            int size = findKClosest(tree1, i, k, set);
            result[i] = size;
        }
        int maxValue = 0;
        for (int i = 0; i < tree2Size; i++) {
            Set<Integer> set = new HashSet<>();
            set.add(i);
            int size = findKClosest(tree2, i, k - 1, set);
            maxValue = Math.max(maxValue, size);
        }
        for (int i = 0; i < tree1Size; i++) {
            result[i] = result[i] + maxValue;
        }
        return result;
    }
    public void constructGraph(int[][] edges, Map<Integer, List<Integer>> tree) {
        for (int i = 0; i < edges.length; i++) {
            int[] edge = edges[i];
            int start = edge[0];
            int end = edge[1];
            if (tree.containsKey(start)) {
                List<Integer> list = tree.get(start);
                list.add(end);
                tree.put(start, list);
            } else {
                List<Integer> list = new ArrayList<>();
                list.add(end);
                tree.put(start, list);
            } 
            if (tree.containsKey(end)) {
                List<Integer> list = tree.get(end);
                list.add(start);
                tree.put(end, list);
            } else {
                List<Integer> list = new ArrayList<>();
                list.add(start);
                tree.put(end, list);
            }   
        }
    }
    public int calculateTreeSize(int[][] edges) {
        int size = 0;
        for (int i = 0; i < edges.length; i++) {
            int[] edge = edges[i];
            size = Math.max(size, edge[0]);
            size = Math.max(size, edge[1]);
        }
        return size + 1;
    }
    public int findKClosest(Map<Integer, List<Integer>> map, int node, int k, Set<Integer> visited) {
        if (!map.containsKey(node) || k < 0) {
            return 0;
        }
        int sum = 1;
        List<Integer> neighbors = map.get(node);
        for (int i = 0; i < neighbors.size(); i++) {
            int neighbor = neighbors.get(i);
            if (!visited.contains(neighbor)) {
                visited.add(neighbor);
                sum = sum + findKClosest(map, neighbor, k - 1, visited);
            }
        }
        return sum;
    }
}