class Pair{
    int v;
    int d;
    public Pair(int v,int d){
        this.v = v;
        this.d = d;
    }
}
class Solution {
    int x =0;
    public int shortestPath(ArrayList<ArrayList<Integer>> g,int s,int e ){
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b)-> a.d-b.d);
        pq.add(new Pair(s,0));
        boolean visited[] =new boolean[e+1];
        while(!pq.isEmpty()){
            Pair p = pq.poll();
            int v = p.v;
            int d = p.d;
            visited[v]=true;
            if(v==e){
                return d;
            }
            ArrayList<Integer> adj = g.get(v);
            for(Integer node : adj){
                if(!visited[node]){
                    pq.add(new Pair(node,d+1));
                }
            }
        }
        return 0;
    }
    public int[] shortestDistanceAfterQueries(int n, int[][] q) {
        ArrayList<ArrayList<Integer>> g = new ArrayList<>();
        for(int i=0; i<n; i++){
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            if(i<n-1){
                tmp.add(i+1);
            }
            g.add(tmp);
        }
        int ans[] = new int[q.length];
        for(int i=0; i<q.length; i++){
            int u = q[i][0];
            int v = q[i][1];
            x++;
            if(u+1!=v){
                g.get(u).add(v);
            }
            ans[i] = shortestPath(g,0,n-1);
        }
        return ans;
    }
}