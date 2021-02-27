/* BFS reverse order traversal

*/
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if (n==1) {
            res.add(0);
            return res;
        }
        Map<Integer, Integer> degreeMap = new HashMap<>();
        Map<Integer, List<Integer>> adjMap = new HashMap<>();
        for (int i=0; i<n; i++) {
            adjMap.put(i, new ArrayList<>());
        }
            
        for (int[] edge: edges) {
            int src = edge[0];
            int target = edge[1];
            adjMap.get(src).add(target);
            adjMap.get(target).add(src);
            degreeMap.put(src, degreeMap.getOrDefault(src,0)+1);
            degreeMap.put(target, degreeMap.getOrDefault(target,0)+1);
        }
        
        return BFS(degreeMap, adjMap, n);      
    }
    
    private List<Integer> BFS(Map<Integer, Integer> degreeMap, Map<Integer, List<Integer>> adjMap, int n) {
        Queue<Integer> q = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            if (degreeMap.containsKey(i) && degreeMap.get(i) == 1) 
                q.add(i);
        }
        
        while(!q.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            int size = q.size();
            for (int i=0; i<size; i++) {
                int curr = q.poll();
                list.add(curr);
                for (int parent: adjMap.get(curr)) {
                    degreeMap.put(parent, degreeMap.get(parent)-1);
                    if (degreeMap.get(parent)==1)
                        q.add(parent);
                }
            }
            res = list;
        }   
        
        return res;
    }   
    
}