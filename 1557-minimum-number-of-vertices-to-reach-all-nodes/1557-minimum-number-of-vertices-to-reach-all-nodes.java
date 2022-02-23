class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
		Set<Integer> res = new HashSet();
        boolean[] visited = new boolean[n];
		for(List<Integer> edge: edges) {
			visited[edge.get(1)] = true;
		}
		for(int i=0; i<visited.length; i++) {
			if(!visited[i]) res.add(i);
		}
        return new ArrayList(res);
    }
}