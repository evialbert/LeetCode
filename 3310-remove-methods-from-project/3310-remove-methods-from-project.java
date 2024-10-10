class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i=0 ; i<n ; i++){
            adj.add(new ArrayList<>());
        }
        int len = invocations.length;
        for (int i=0; i<len ; i++){
            adj.get(invocations[i][0]).add(invocations[i][1]);
        }
        int[] vis = new int[n];
        if (vis[k] == 0) dfs(adj,k,vis);
        int iniZero = 0;
        for (int i=0 ; i<n ; i++){
            if (vis[i] == 0) iniZero++;
        }
        for (int i=0 ; i<n ; i++){
            if (vis[i] == 0){
                reverseDfs(adj,i,vis);
            }
        }
        int secZero = 0;
        for (int i=0 ; i<n ; i++){
            if (vis[i] == 0) secZero++;
        }
        List<Integer> list1 = new ArrayList<>();
        for (int i=0 ; i<n ; i++){
            list1.add(i);
        }
        List<Integer> list = new ArrayList<>();
        for (int i=0 ; i<n ; i++){
            if (vis[i] == 0) list.add(i);
        }
        return iniZero!=secZero ? list1 : list;
    }

    public void reverseDfs(List<List<Integer>> adj , int src , int[] vis){
        vis[src] = 0;
        for (int it: adj.get(src)){
            if (vis[it] == 1){
                reverseDfs(adj,it,vis);
            }
        }
    }

    public void dfs(List<List<Integer>> adj , int src , int[] vis){
        vis[src] = 1;
        for (int it: adj.get(src)){
            if (vis[it] == 0){
                dfs(adj,it,vis);
            }
        }
    }
}