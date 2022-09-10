class Solution {
    public boolean[] friendRequests(int n, int[][] restrictions, int[][] requests) {
        UnionFind uf = new UnionFind(n);
        boolean[] answer = new boolean[requests.length];
        int k = 0;
        for(int[] friends: requests)
        {
            int p1 = uf.Find(friends[0]);
            int p2 = uf.Find(friends[1]);
            boolean request = true;
            if(p1 != p2)
            {
                for(int[] block: restrictions)
                {
                    int x = uf.Find(block[0]), y = uf.Find(block[1]);
                    if(p1 == x && p2 == y || p1 == y && p2 == x)
                    {
                        request = false;
                        break;
                    }    
                }
            }
            
            if(request)
                uf.Union(p1, p2);
            answer[k++] = request;
        }
        return answer;
    }
    
    class UnionFind {
        int[] parent;
        
        public UnionFind(int len){
            parent = new int[len];
            for(int i = 0; i < len; i++)
                parent[i] = i;
        }
        
        private int Find(int node)
        {
            if(parent[node] != node)
                parent[node] = Find(parent[node]);
            
            return parent[node];
        }
        
        private void Union(int a, int b)
        {
            int parentA = Find(a);
            int parentB = Find(b);
            
            parent[parentA] = parentB;
        }
        
    }
}