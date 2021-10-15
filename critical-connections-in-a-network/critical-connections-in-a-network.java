class Solution {
    int[] disc;
    int[] low;
    int[] par;
    boolean[] vis;
    int time;
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        ArrayList<ArrayList<Integer>> graph=new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }
        for(int i=0;i<connections.size();i++){
            int u=connections.get(i).get(0);
            int v=connections.get(i).get(1);
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        disc=new int[n];
        low=new int[n];
        par=new int[n];
        vis=new boolean[n];
        time=0;
        List<List<Integer>> ans=new ArrayList<>();
        dfs(0,graph,ans);
        return ans;
    }
    
    public void dfs(int vtx,ArrayList<ArrayList<Integer>> graph,List<List<Integer>> ans){
        disc[vtx]=low[vtx]=time++;
        vis[vtx]=true;
        
        for(int i=0;i<graph.get(vtx).size();i++){
            int nbr=graph.get(vtx).get(i);
            if(par[vtx]==nbr){
                continue;
            }else if(vis[nbr]==true){
                low[vtx]=Math.min(low[vtx],disc[nbr]);
            }else{
                par[nbr]=vtx;
                dfs(nbr,graph,ans);
                
                low[vtx]=Math.min(low[nbr],low[vtx]);
                if(low[nbr]>disc[vtx]){
                    List<Integer> temp=new ArrayList<>();
                    temp.add(vtx);
                    temp.add(nbr);
                    ans.add(temp);
                }
            }
        }
    }
}