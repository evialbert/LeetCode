class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> lossCount = new TreeMap<>();
        for(int[] match : matches) {
            if(!lossCount.containsKey(match[0])) {
                lossCount.put(match[0], 0);
            }
            lossCount.put(match[1], lossCount.getOrDefault(match[1], 0) + 1);
        }
        
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> noLose = new ArrayList<>();
        List<Integer> oneLose = new ArrayList<>();
        for(int player : lossCount.keySet()) {
            if(lossCount.get(player) == 0) {
                noLose.add(player);
            } else if(lossCount.get(player) == 1) {
                oneLose.add(player);
            }
        }
        
        res.add(noLose);
        res.add(oneLose);
        
        return res;
    }
}