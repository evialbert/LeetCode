class Solution {
    public class Pair implements Comparable<Pair>{
        int dest;
        int wt;
        Pair(int dest,int wt){
            this.dest=dest;
            this.wt=wt;
        }
        public int compareTo(Pair o){
            return this.wt-o.wt;
        }
    }
    
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        List<List<Pair>> graph=new ArrayList<>();
        
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }
        
        for(int[] a:edges){
            graph.get(a[0]).add(new Pair(a[1],a[2]));
            graph.get(a[1]).add(new Pair(a[0],a[2]));
        }
        boolean[] vis=new boolean[n];
        
        
        int[] time =new int[n];
        Arrays.fill(time, Integer.MAX_VALUE);
        
        time[0]=0;
        PriorityQueue<Pair> pq=new PriorityQueue<>();
        pq.add(new Pair(0,0));
        
        while(!pq.isEmpty()){
           
            Pair rem=pq.remove();
            int t=rem.wt;
            int v=rem.dest;
            if(vis[v]){
                continue;
            }
            vis[v]=true;
            
            for(Pair pair : graph.get(v)){
                int dist=pair.wt;
                int ver=pair.dest;
                if(dist+t<time[ver] && disappear[ver]>dist+t && vis[ver]!=true){
                    time[ver]=dist+t;
                    pq.add(new Pair(ver,time[ver]));
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(time[i]==Integer.MAX_VALUE){
                time[i]=-1;
            }
        }
        return time;
    }
}