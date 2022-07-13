class Solution {

    public boolean validPath(int n, int[][] edges, int source, int destination) {
       Map<Integer,List<Integer>>adjList=new HashMap<>();
        Map<Integer,Boolean>visited=new HashMap<>();
        for(int i=0;i<n;i++){
            adjList.put(i, new ArrayList<>());
            visited.put(i,false);
        }
        
        for(int i=0 ; i<edges.length;i++){
                int u=edges[i][0];
                int v=edges[i][1];

                adjList.get(u).add(v);
                adjList.get(v).add(u);
        }
        
        Queue<Integer>q= new LinkedList<>();
        q.add(source);
        visited.replace(source,true);
        
        while(!q.isEmpty()){
            int top=q.poll();
            if(top==destination){
                return true;
            }
            
            for(Integer ele:adjList.get(top)){
                if(!visited.get(ele)){
                    q.add(ele);
                    visited.replace(ele,true);
                }
            }
        }
        
        return false;
    }
}