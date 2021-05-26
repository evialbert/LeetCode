class Solution {
    int result[]=new int[2];
    public int getParent(int parent[],int node)
    {
        while(node!=parent[node])
            node=parent[node];
        return node;
    }
    public boolean find(int i,int j,int parent[])
    {
        return getParent(parent,i)==getParent(parent,i);
    }
    public boolean union(int parent[],int i,int j,int count[])
    {
        int Parent_i=getParent(parent,i);
        int Parent_j=getParent(parent,j);
        if(Parent_i==Parent_j) 
        {
            result[0]=i;
            result[1]=j;
            return true;
        }
        if(count[Parent_i]>count[Parent_j])
        {
            parent[Parent_j]=Parent_i;
            count[Parent_i]+=count[Parent_j];
        }
        else
        {
            parent[Parent_i]=Parent_j;
            count[Parent_j]+=count[Parent_i];
        }
        return false;
    }
    public int[] findRedundantConnection(int[][] edges) {
        if(edges==null) return new int[0];
        int n=edges.length+1;
        int parent[]=new int[n];
        int count[]=new int[n];
        
        for(int i=1;i<n;i++){
            parent[i]=i;
            count[i]=1;
        }
        
        for(int edge[]:edges)
        {
            if(union(parent,edge[0],edge[1],count))
                break;
        }
        return result;
    }
}