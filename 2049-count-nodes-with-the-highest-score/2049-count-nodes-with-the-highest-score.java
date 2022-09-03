class Solution {
    HashMap<Integer, ArrayList<Integer>> children = new HashMap<Integer, ArrayList<Integer>>();
    HashMap<Long, Integer> map = new HashMap<Long, Integer>();
    long max = 0L;
    public int countHighestScoreNodes(int[] parents) {
        for (int i = 1; i < parents.length; i++){
            if (!children.containsKey(parents[i])){
                children.put(parents[i], new ArrayList<Integer>());
            }
            children.get(parents[i]).add(i);
        }
        dfs(parents, 0);
        return map.get(max);
    }
    
    public long dfs(int[] parents, int root){
        var arr = new ArrayList<Integer>();
        if (children.containsKey(root)){
            arr = children.get(root);
        }
        
        long sum = 1L;
        long product = 1L;
        for (var num:arr){
            var e = dfs(parents, num);
            sum += e;
            product *= e;
        }
        long score = Math.max(parents.length-sum,1)*product;
        if (!map.containsKey(score)){
            map.put(score, 0);
        }
        map.put(score, map.get(score)+1);
        max = Math.max(max, score);
        return sum;
    }
}