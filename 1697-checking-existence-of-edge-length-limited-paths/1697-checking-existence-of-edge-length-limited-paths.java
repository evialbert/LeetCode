class Solution {
    public int[] root;
    public int findRoot(int x)
    {
        if(x!=root[x])
        {
            root[x]=findRoot(root[x]);
        }
        return root[x];
    }
    public void union(int x, int y)
    {
        root[findRoot(x)]=findRoot(y);
    }
    public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) {
        root=new int[n];
        for(int i=0; i<n; i++)
        {
            root[i]=i;
        }
        TreeMap<Integer, ArrayList<int[]>> q=new TreeMap<>();
        for(int i=0; i<queries.length; i++)
        {
            if(!q.containsKey(queries[i][2]))
            {
                q.put(queries[i][2], new ArrayList<int[]>());
            }
            q.get(queries[i][2]).add(new int[]{queries[i][0], queries[i][1], i});
        }
        Arrays.sort(edgeList, new Comparator<int[]>(){
            public int compare(int[] a, int[] b)
            {
                return Integer.compare(a[2], b[2]);   
            }
        });
        boolean[] res=new boolean[queries.length];
        int i=0;
        for(Map.Entry<Integer, ArrayList<int[]>> e:q.entrySet())
        {
            for(int[] l:e.getValue())
            {
                while(i<edgeList.length && edgeList[i][2]<e.getKey())
                {
                    if(findRoot(edgeList[i][0])!=findRoot(edgeList[i][1]))
                    {
                        union(edgeList[i][0], edgeList[i][1]);   
                    }
                    i++;
                }
                res[l[2]]=findRoot(l[0])==findRoot(l[1]);
            }
        }
        return res;
    }
}