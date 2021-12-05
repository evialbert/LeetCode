class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        List<Integer>[] graph = (List<Integer>[]) new ArrayList[n+1];
        for (int i=1; i<=n; i++) graph[i]=new ArrayList<>();
        for (int[] edge: edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        boolean[] visited = new boolean[n+1];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] {1, 1});
        visited[1]=true;
        int step=0;
        while (!queue.isEmpty()&&step<=t) {
            int size = queue.size();
            for (int i=0; i<size; i++) {
                int[] curr = queue.poll();
                int b=0;
                for (int w: graph[curr[0]]) {
                    if (!visited[w]) b++;
                }
                if (curr[0]==target&&(b==0||step==t)) return 1.0/curr[1];
                for (int w: graph[curr[0]]) {
                    if (!visited[w]) {
                        visited[w]=true;
                        queue.offer(new int[] {w, curr[1]*b});
                    }
                }
            }
            step++;
        }
        return 0.0;
    }
}