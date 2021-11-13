class Solution {
    public class UnionFind{
            
        int[] parent, size;
        int components;

        public UnionFind(int n){

            parent= new int[n];
            size= new int[n];
            components= n;

            for (int i=0; i<n; i++){
                parent[i]= i;
                size[i]= 1;
            }
        }

        private int find(int p){

            ArrayList<Integer> c= new ArrayList<>();

            while (parent[p] != p) {
                c.add(p);
                p= parent[p];
            }

            for (int component: c){
                parent[component]= p;
            }

            return p;
        }

        public void union(int p, int q){

            int parentP= find(p);
            int parentQ= find(q);

            if(parentP != parentQ){
                if(size[parentP]> size[parentQ]){
                    parent[parentQ]= parentP;
                    size[parentP]+= size[parentQ];
                } else {
                    parent[parentP]= parentQ;
                    size[parentQ]+= size[parentP];
                }
                components--;
            }
        }
    }
    
    public int makeConnected(int n, int[][] connections) {
        
        int wiresAvailable= 0;
        int connectionNeeded= n-1;
        
        UnionFind uf= new UnionFind(n);
        
        for (int[] connection: connections){
            if(uf.find(connection[0])== uf.find(connection[1])) wiresAvailable++;
            else {
                uf.union(connection[0], connection[1]);
                connectionNeeded--;
            };
        }
        
        return connectionNeeded<= wiresAvailable? connectionNeeded: -1;
    }
}