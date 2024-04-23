class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) return {0};
		vector<int> adj[n];
		vector<int> inDegree(n);
		for (auto &e : edges) {
			int u = e[0], v = e[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
			++inDegree[u];
			++inDegree[v];
		}
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (inDegree[i] == 1) q.push(i);
		}

		vector<int> ans;
		while (q.size()) {
			int sz = q.size();
			ans.clear();
			while (sz--) {
				int node = q.front(); q.pop();
				ans.push_back(node);
				for (auto &e : adj[node]) {
					inDegree[e]--;
					if (inDegree[e] == 1) q.push(e);
				}
			}
		}
		return ans;
	}
};