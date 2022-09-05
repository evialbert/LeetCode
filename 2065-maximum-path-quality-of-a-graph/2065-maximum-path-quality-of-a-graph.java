class Solution {
    int result = 0;
    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        int[] visited = new int[n];
        
        Map<Integer, List<int[]>> map = new HashMap<>();
        
        for(int[] e: edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            
            map.putIfAbsent(u, new ArrayList<>());
            map.putIfAbsent(v, new ArrayList<>());
            
            map.get(u).add(new int[]{v, t});
            map.get(v).add(new int[]{u, t});
        }
        
        int start = 0;
        int total = values[start];
        visited[start]++;
        dfs(values, visited, map, maxTime, total, start);
        return result;
    }
    
    private void dfs(int[] values, int[] visited, Map<Integer, List<int[]>> map, int maxTime, int total, int start) {
        if(start == 0) {
            result = Math.max(result, total);
        }
        
        if(map.get(start) == null) {
            return;
        }
        
        for(int[] i: map.get(start)) {
            int dest = i[0];
            int time = i[1];
            int newTime = maxTime - time;
            if(newTime < 0) {
                continue;
            }
            
            visited[dest]++;
            int newValue = total + (visited[dest] != 1 ? 0 : values[dest]);
            dfs(values, visited, map, newTime, newValue, dest);
            visited[dest]--;
        }
    }
}