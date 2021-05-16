class Solution {
    
    Random r = new Random();
    Set<Integer> set = new HashSet<>();
    Map<Integer, Integer> map = new HashMap<>();
    int range;
    
    public Solution(int N, int[] blacklist) {
        
        int BLen = blacklist.length;
        int WLen = N- BLen;
        range = WLen;
        
        for (int num : blacklist){
            if (num >= WLen)
                set.add(num);
        }
        
        int j = WLen;
        for (int num : blacklist){
            if (num < WLen){
                while(set.contains(j))
                    j++;
                map.put(num,j++);
            }
        }
    }
    public int pick() {
        int key = r.nextInt(range);
        return map.getOrDefault(key, key);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n, blacklist);
 * int param_1 = obj.pick();
 */