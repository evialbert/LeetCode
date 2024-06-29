class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        
        HashMap<Integer, List<Integer>> ancestor = new HashMap<>();
        for(int i = 0; i < n;i++){
            ancestor.put(i,new ArrayList<>());
        }
        for(int[] arr : edges){
            List<Integer> list = ancestor.getOrDefault(arr[1], new ArrayList<>());
            list.add(arr[0]);
            ancestor.put(arr[1], list);
        }

        List<List<Integer>> ans = new ArrayList<>();
        for(int i = 0; i < n; i++){
            List<Integer> temp = ancestor.get(i);
            addAncestors(temp, ancestor,n);
            Collections.sort(temp);
            ans.add(temp);
        }
        return ans;
    }
    void addAncestors(List<Integer> list, HashMap<Integer, List<Integer>> ancestor, int n){
        if(list.size() == 0) return;

        boolean[] visited = new boolean[n]; 
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < list.size(); i++){
            queue.offer(list.get(i));
            visited[list.get(i)] = true;
        }

        while(!queue.isEmpty()){
            int top = queue.poll();
            List<Integer> temp = ancestor.get(top);

            for(int node : temp){
                if(!visited[node]){
                    queue.offer(node);
                    visited[node] = true;
                    list.add(node);
                }
            }
        }
    }
}