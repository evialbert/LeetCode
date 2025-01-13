class Solution {
    static int par[];
    static int rank[];
    static int size[];

    static int find(int a){
        if(par[a]==a) return a;
        else return par[a] = find(par[a]);
    }

    static void union(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;

        if(rank[a]>=rank[b]){
            par[b] = a;
            rank[a]++;
            size[a]+=size[b]; 
        }else{
            par[a] = b;
            rank[b]++;
            size[b]+=size[a];
        }
    }
    public long countPairs(int n, int[][] edges) {
        par = new int[n];
        size = new int[n];
        rank = new int[n];
        if(edges.length==0){
            long x = (long)(n-1);
            return (x*(x+1))/2;
        }
        for(int i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
        }

        for(int i=0; i<edges.length; i++){
            union(edges[i][0],edges[i][1]);
        }

        long sum = 0;
        long ans = 0;
       

        for(int i=0; i<n; i++){
            if(par[i]==i){
                ans = ans + sum*size[i];
                sum = sum + size[i];
            }
        }
        return ans;
        
    }
}