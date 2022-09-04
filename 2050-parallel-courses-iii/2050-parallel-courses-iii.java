class Solution {
    ConcurrentHashMap<Integer, ArrayList<Integer>> hm;
    
    int getMaxTime(int[] time, int key, ArrayList<Integer> al) {
        int max_time = 0;
        for(int i : al) {
            if(hm.containsKey(i)) {
                int t = time[i-1] + getMaxTime(time, i, hm.get(i));
                max_time = Math.max(max_time, t);
                time[i - 1] = t;
                hm.remove(i);
            } else {
                max_time = Math.max(max_time, time[i - 1]);
            }
        }
        return max_time;
    }
    
    public int minimumTime(int n, int[][] relations, int[] time) {
        int max = 0;
        for(int i : time) {
            max = Math.max(max, i);
        }
        hm = new ConcurrentHashMap<>();
        
        for(int[] relation : relations) {
            if(!hm.containsKey(relation[1])) {
                hm.put(relation[1], new ArrayList<>());
            }
            hm.get(relation[1]).add(relation[0]);
        }
        
        for(int key : hm.keySet()) {
            if(hm.containsKey(key)) {
                max = Math.max(max, time[key-1] + getMaxTime(time, key, hm.get(key)));
            }
        }
        return max;
    }
}