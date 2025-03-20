class Solution {
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        
        int[] answer = new int[query.length];
        int component = 1;
        boolean[] vis = new boolean[n];

        int[] nodeToComp = new int[n];
        int[] compToBitwiseAnd= new int[n+1];

        HashMap<Integer, List<int[]>> map = new HashMap<>();

        for (int i = 0; i < n+1; i++) {
            compToBitwiseAnd[i]=Integer.MAX_VALUE;
        }

        for (int i = 0; i < edges.length; i++) {
            int[] arr1 = {edges[i][1], edges[i][2]};
            int[] arr2 = {edges[i][0], edges[i][2]};
            map.computeIfAbsent(edges[i][0], (k) -> new ArrayList<>()).add(arr1);
            map.computeIfAbsent(edges[i][1], (k) -> new ArrayList<>()).add(arr2);

          
        }

        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                queue.add(i);
                //decide component for each node
                while (!queue.isEmpty()) {

                    int v = queue.poll();
                    if (!vis[v] && map.containsKey(v)) {
                        List<int[]> list = map.get(v);
                        for (int j = 0; j < list.size(); j++) {
                            queue.offer(list.get(j)[0]);
                            compToBitwiseAnd[component] = compToBitwiseAnd[component] & list.get(j)[1];
                        }
                    }
                    if (!vis[v]) {
                        nodeToComp[v] = component;
                        vis[v] = true;

                    }
                }
                component++;
            }
        }

        //if same component do bitwise AND, different component return -1, same node return 1

        for (int i = 0; i < query.length; i++) {
            int source = query[i][0];
            int des = query[i][1];
            if(source==des){
                answer[i]=0;
            }else if(nodeToComp[source]==nodeToComp[des]){
                answer[i]=compToBitwiseAnd[nodeToComp[source]];
            }else answer[i]=-1;
        }

        return answer;
    }
}