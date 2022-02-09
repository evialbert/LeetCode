//Java Dijkstra Algorithm
class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        PriorityQueue<edge> pq = new PriorityQueue<>((a, b) -> {
            return Double.compare(b.w, a.w); // larger weight(success probability) go first 
        });
        boolean [] vis = new boolean[n];
        double [] dis = new double[n];
        List<edge> [] adj = new List[n];
        for (int i = 0; i<n; i++) adj[i] = new ArrayList<>();
        int idx = 0;
        for (int [] nxt : edges) {
            adj[nxt[0]].add(new edge(nxt[1], succProb[idx]));
            adj[nxt[1]].add(new edge(nxt[0], succProb[idx]));
            idx++;
        }
        pq.add(new edge(start, 1.0));
        while (pq.size() > 0) {
            edge cur = pq.poll();
            if (cur.w <= dis[cur.dest]) continue;
            dis[cur.dest] = cur.w;
            vis[cur.dest] = true;
            for (edge nxt : adj[cur.dest]) {
                if (vis[nxt.dest]) continue;
                pq.add(new edge(nxt.dest, dis[cur.dest] * nxt.w));
            }
        }
        return dis[end];
    }
    public class edge {
        int dest;
        double w;
        edge(int u, double succ) { dest = u; w = succ; }
    }
}