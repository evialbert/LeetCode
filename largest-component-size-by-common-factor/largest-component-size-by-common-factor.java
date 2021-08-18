class Solution {
    public int largestComponentSize(int[] A) {
        UF uf = new UF(A.length);
        
        Map<Integer, Integer> map = new HashMap<>();        
        for (int i = 0; i < A.length; i++)
        {            
            for (int j = 2; j * j <= A[i]; j++)
            {
                if (A[i] % j == 0)
                {
                    if (map.containsKey(j) && uf.find(i) != map.get(j))
                    {
                        uf.union(i, map.get(j));
                    }
                    else if (!map.containsKey(j))
                    {
                        map.put(j, i);
                    }
                    
                    if (map.containsKey(A[i] / j) && uf.find(i) != map.get(A[i] / j))
                    {
                        uf.union(i, map.get(A[i] / j));
                    }
                    else if (!map.containsKey(A[i] / j))
                    {
                        map.put(A[i] / j, i);
                    }
                }
            }
            
            if (map.containsKey(A[i]) && uf.find(i) != map.get(A[i]))
            {
                uf.union(i, map.get(A[i]));
            }
            else if (!map.containsKey(A[i]))
            {
                map.put(A[i], i);
            }
        }
        
        int[] counts = new int[A.length];
        int max = 0;
        
        for (int i = 0; i < A.length; i++)
        {
            counts[uf.find(i)]++;
            max = Math.max(max, counts[uf.find(i)]);
        }
        
        return max;
    }
    
    class UF
    {
        int[] roots;
        
        public UF(int length)
        {
            roots = new int[length];
            
            for (int i = 0; i < roots.length; i++)
            {
                roots[i] = i;
            }       
        }
        
        public void union(int i, int j)
        {   
            roots[find(i)] = roots[find(j)];
        }
        
        public int find(int i)
        {
            if (roots[i] != i)
            {
                roots[i] = find(roots[i]);
            }
            
            return roots[i];
        }
    }
}