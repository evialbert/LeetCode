class Solution {
   public List<List<String>> accountsMerge(List<List<String>> accounts) {

	HashMap<String, String> owners = new HashMap<String, String>();
	HashMap<String, List<String>> graph = new HashMap<String, List<String>>();

	for (List<String> account : accounts) {
		String name = account.get(0);
		int length = account.size();
		for (int i = 1; i < length; i++) {
			String curr = account.get(i);
			String prev = account.get(i - 1);
			if (!graph.containsKey(curr))
				graph.put(curr, new ArrayList<String>());
			owners.put(curr, name);
			if (i == 1)
				continue;
			graph.get(curr).add(prev);
			graph.get(prev).add(curr);
		}
	}

	HashSet<String> visited = new HashSet<String>();
	List<List<String>> ans = new ArrayList<List<String>>();
	for (String email : owners.keySet()) {
		if (!visited.contains(email)) {
			List<String> res = new ArrayList<String>();
			dfs(graph, visited, email, res);
			Collections.sort(res);
			res.add(0, owners.get(email));
			ans.add(res);
		}
	}
	return ans;
}

public void dfs(HashMap<String, List<String>> graph, HashSet<String> visited, String curr, List<String> res) {
	res.add(curr);
	visited.add(curr);
	List<String> nbrs = graph.get(curr);
	for (String nbr : nbrs) {
		if (!visited.contains(nbr))
			dfs(graph, visited, nbr, res);
	}
}
}