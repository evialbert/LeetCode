class Solution {
    double[] result;
    Set<String> visited;
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        
        // create graph
        Map<String, ArrayList<Pair<String, Double>>> graph = new HashMap<>();        
        for (int i = 0; i < equations.size(); i++) {            
            graph.putIfAbsent(equations.get(i).get(0), new ArrayList<>());            
            graph.putIfAbsent(equations.get(i).get(1), new ArrayList<>());
            graph.get(equations.get(i).get(0)).add(new Pair(equations.get(i).get(1), values[i]));
            graph.get(equations.get(i).get(1)).add(new Pair(equations.get(i).get(0), 1/values[i]));
        }
        
        //initialize
        visited = new HashSet<>();
        result = new double[queries.size()];
        Arrays.fill(result, -1.0);
        int i = 0;
        
        // dfs on each query
        for (List<String> query : queries) {
            visited.clear();
            dfs(graph, query.get(0), 1, query.get(1), i++);
        }
        
        return result;        
    }
    
    public void dfs(Map<String, ArrayList<Pair<String, Double>>> graph, String src, double val, String dest, int ind) {
        // error check
        if (!graph.containsKey(src) || visited.contains(src)) return;
        visited.add(src);
        
        for (Pair p : graph.get(src)) 
            dfs(graph, (String)p.getKey(), (val * (double) p.getValue()), dest, ind);
        
        // base case
        if (src.equals(dest)) {
            result[ind] = val;
            return;
        }
    }
}