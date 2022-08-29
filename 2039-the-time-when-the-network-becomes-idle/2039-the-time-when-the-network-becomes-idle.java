class Solution {
    public int networkBecomesIdle(int[][] edges, int[] p) {
        
            ArrayList<Integer>[] graph=new ArrayList[p.length];
        
            for(int i=0;i<p.length;i++)
            {
                graph[i]=new ArrayList<Integer>();
                
            }
        
            for(int i=0;i<edges.length;i++)
            {
                int v=edges[i][0];
                int nbr=edges[i][1];
                
                graph[v].add(nbr);
                graph[nbr].add(v);
            }
            Integer[] level=new Integer[p.length];
            Queue<Integer> q=new ArrayDeque<>();
            q.add(0);
            level[0]=0;
            int l=0;
            while(!q.isEmpty())
            {
                int size=q.size();
                l++;
                for(int i=0;i<size;i++)
                {
                    int rem=q.remove();
                    for(Integer e:graph[rem])
                    {
                        if(level[e]==null)
                        {
                            q.add(e);
                            level[e]=l;
                        }
                    }
                    
                
                    
                }
                
                
            }
            int max=0;
            for(int i=0;i<p.length;i++)
            {
                if(p[i]>=2*level[i])
                {
                    max=Math.max(max,2*level[i]);
                }
                else 
                {
                    max=Math.max(((2*level[i]-1)/p[i])*p[i]+2*level[i],max);
                    
                }
            }
            return max+1;
        
        
        
    }
}