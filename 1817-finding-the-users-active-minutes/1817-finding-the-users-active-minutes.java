class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Map<Integer, Set<Integer>> mp = new HashMap<>();
        int[] result = new int[k];
        
        for(int[] log : logs) {
            mp.putIfAbsent(log[0], new HashSet<Integer>());
            mp.get(log[0]).add(log[1]);
        }   
        
        for(int key : mp.keySet())
            result[mp.get(key).size()-1]++;
        
        return result;
    }
}