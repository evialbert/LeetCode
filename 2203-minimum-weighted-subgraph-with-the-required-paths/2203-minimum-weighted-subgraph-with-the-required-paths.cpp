class Solution {
	long MAXX = 1e10;
public:
	// DIJKSTRA
	void Dijkstra(long src, vector<pair<long, long>> adj[], vector<long>&minDistanceFromSrcTo)
	{
		priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
		pq.push({0, src});
		minDistanceFromSrcTo[src] = 0;
		long u, v, wt, dist;
		while (!pq.empty()) {
			u = pq.top().second;
			dist = pq.top().first;
			pq.pop();
			// below if satement is Dijkstra optimization which lead to solution of TLE
			// don't understand go on top of solution i had pasted that link Dijkstra Optimization
			if (minDistanceFromSrcTo[u] < dist) continue;
			for (auto it : adj[u]) {
				v = it.first;
				wt = it.second;
				if (minDistanceFromSrcTo[u] + wt < minDistanceFromSrcTo[v]) {
					minDistanceFromSrcTo[v] = wt + minDistanceFromSrcTo[u];
					pq.push({minDistanceFromSrcTo[v], v});
				}
			}
		}
	}

	long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
		vector<pair<long, long>> adj[n], revadj[n];
		for (auto e : edges) {
			adj[e[0]].push_back({e[1], e[2]});
			revadj[e[1]].push_back({e[0], e[2]});
		}

		vector<long>fromSrc1To(n, MAXX), fromSrc2To(n, MAXX), fromDestTo(n, MAXX);
		Dijkstra(src1, adj, fromSrc1To);
		Dijkstra(src2, adj, fromSrc2To);
		Dijkstra(dest, revadj, fromDestTo);

		// BASE CASE : not found any path from src1 to dest OR src2 to dest then return -1
		if (fromSrc1To[dest] == MAXX || fromSrc2To[dest] == MAXX) return -1;

		long ans = MAXX;
		for (long i = 0; i < n; i++) {
			ans = min(ans, fromSrc1To[i] + fromSrc2To[i] + fromDestTo[i]);
		}
		return ans;
	}
};