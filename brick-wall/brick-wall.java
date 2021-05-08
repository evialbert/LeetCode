class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int max = 0;
        for(int i = 0; i < wall.size(); i++){
            List<Integer> x = wall.get(i);
            int prevSum = 0;
            for(int j = 0; j < x.size() - 1; j++){ 
                prevSum = prevSum + x.get(j);
                if(!map.containsKey(prevSum))
                    map.put(prevSum, 1);
                else
                    map.put(prevSum, map.get(prevSum) + 1);
            }
        }
        List<Integer> values = new ArrayList<>(map.values());
        if(values.size() > 0)
            max = Collections.max(values);
        return wall.size() - max;
    }
}