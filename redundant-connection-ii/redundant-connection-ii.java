class Solution {
    
    public class UnionFind{
        private int[] parent;
        public UnionFind(int n){
            parent = new int[n];
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        
        public int find(int x){
            while(x != parent[x]){
                parent[x] = find(parent[x]);
                x = parent[x];
            }
            return x;
        }
        
        public void union(int x, int y){
            parent[find(x)] = find(y);
        }
        
        public boolean isConnected(int x, int y){
            int rootX = find(x), rootY = find(y);
            return rootX == rootY;
        }
    }
    
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int len = edges.length;
        UnionFind uf = new UnionFind(len + 1);
        int[] parent = new int[len + 1];
        for(int i = 1; i <= len; i++){
            parent[i] = i;
        }
        int conflict = -1;
        int cycle = -1;
        for(int i = 0; i < len; i++){
            int[] edge = edges[i];
            int node1 = edge[0], node2 = edge[1];
            // means already modified in prev edge
            if(parent[node2] != node2){
                conflict = i;
            } else{
                //first update
                parent[node2] = node1;
                //connected check cycle
                if(uf.find(node1) == uf.find(node2)){
                    cycle = i;
                } else{
                //not connected
                    uf.union(node1, node2);
                }
            }
        }
        System.out.println(conflict);
        System.out.println(cycle);
        if(conflict < 0){
            //no conflict, return first cycle happen place
            return new int[]{edges[cycle][0], edges[cycle][1]};
        } else{
            int[] conflictEdge = edges[conflict];
            if(cycle >= 0){
                //have conflict and cycle, return conflict parent and itself
                return new int[]{parent[conflictEdge[1]], conflictEdge[1]};
            }else{
                //return last conflict
                return new int[]{conflictEdge[0], conflictEdge[1]};
            }
        }
    }
}