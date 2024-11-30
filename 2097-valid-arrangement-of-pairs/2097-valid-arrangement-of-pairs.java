class Solution {
    // map to track all outcoming edges for given vertex
    HashMap<Integer, Stack<Integer>> map = new HashMap<>();

    public int[][] validArrangement(int[][] pairs) {
        
        // map to calculate outdegree - indegree
        HashMap<Integer, Integer> degrees = new HashMap<>();

        for (int[] p : pairs) {
            if ( ! map.containsKey(p[0])) {
                map.put(p[0], new Stack<>());
            }
            map.get(p[0]).push(p[1]);

            degrees.put(p[0], degrees.getOrDefault(p[0], 0)-1);
            degrees.put(p[1], degrees.getOrDefault(p[1], 0)+1);
        }

        /*
            Based on task description our graph at least has Eulerian path
            or possible even circle.
            If it has circle, we can start from any node (let's take the first vertex)
            If the graph has Eulerian path only, in this case there will be exactly
            one vertex with degree -1, this will be our start node.
        */
        int start = pairs[0][0];
        for (int[] p : pairs) {
            if (degrees.get(p[0]) == -1) {
                start = p[0];
                break;
            }
        }

        // build the path in reverse order
        List<Integer> path = new ArrayList<>();        
        calculate(start, path);
        // reverse it
        Collections.reverse(path);

        int[][] res = new int[pairs.length][2];

        // build the result
        for (int i = 1; i < path.size(); i++) {
            res[i-1][0] = path.get(i-1);
            res[i-1][1] = path.get(i);
        }

        return res;
    }

    public void calculate(int v, List<Integer> path) {
        while (map.containsKey(v) && map.get(v).size() > 0) {
            calculate(map.get(v).pop(), path);
        }
        path.add(v);
    }
}