class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        int result=0;
        boolean[] visit=new boolean[n];
        
        for(int i=0;i<n;i++){
            
            if(visit[i]==false){
                DFS(isConnected,visit,i);
                    result++;
            }
             
        }
        
        return result;
    }
    
  void DFS(int[][] matGraph,boolean[] visit,int curr){
        
        visit[curr]=true;
        int[]  connection=matGraph[curr];
        
        for(int i=0;i<connection.length;i++){
            
            if(connection[i]==0 || visit[i]) //connection[i]==0 indicate No connection 
                continue;
            
             DFS(matGraph,visit,i);
        }
      
    }
}