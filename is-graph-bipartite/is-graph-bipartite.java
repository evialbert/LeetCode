/**
    Intuition: Each node is seperated into two different parties (0, 1). We do a dfs to distinguish the parties. 
    If at any moment, we find the party of two adjacent nodes is same, it means we can't divide the graph 
    into two different parties. Since there could be interdepency. 
    
    So we do a DFS + Party Map. 
    Time Complexity: O(N+E) : N is the number of nodes in graph, E is the number of edges 
    Space Complexity: O(N)
**/
class Solution {
    public boolean isBipartite(int[][] graph) {
        Set<Integer> visited = new HashSet<>();
        for(int i= 0; i < graph.length; i++) {
            dfs(graph, i, visited, new HashMap<>());
            if(!res) {
                return res;
            }
        }
        return true;
    }
    
    boolean res = true;
    
    void dfs(int[][] graph , int i, Set<Integer> visited , Map<Integer, Integer> party) {
        if(visited.contains(i)) {
            return;
        }
        
        visited.add(i);
        
        for(int j =0; j < graph[i].length; j++) {
            int x = i;
            int y = graph[i][j];
            
            Integer a= party.get(x);
            Integer b = party.get(y);
            if(a == null &&  b == null) {
                party.put(x, 0);
                party.put(y, 1);
            } else if(a == null && b != null) {
                party.put(x, (b + 1) % 2);
            } else if(a != null && b == null) {
                party.put(y, (a + 1) % 2);
            } else if(a != null && b != null) {
                if(a.equals(b)) {
                    res = false;
                    return;
                }
            }
            
            dfs(graph, y, visited, party);
        }
    }
    
}