class AllOne {
    Map<Integer, Set<String>> map = new HashMap<>();
    Map<String, Integer> counts = new HashMap<>();
    /** Initialize your data structure here. */
    int max =1;
    public AllOne() {
        map.put(0, new HashSet<>());
        map.get(0).add("");
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        int lev = counts.getOrDefault(key, 0)+1;
        map.putIfAbsent(lev, new HashSet<>());
        map.get(lev).add(key);
        map.get(lev-1).remove(key);
        counts.put(key, lev);
        if(lev>max) max= lev;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        int lev = counts.getOrDefault(key, 0);
        if(lev==0) return;
        if(lev==1) {
            counts.remove(key);
            map.get(lev).remove(key);
        } else {
            counts.put(key, lev-1);
            map.get(lev).remove(key);
            map.get(lev-1).add(key);
            if(lev==max && map.get(lev).isEmpty()) max--;
        }
    }
    
    /** Returns one of the keys with maximal value. */
	//This is linear time in the worst case
    public String getMaxKey() {
        while(max >=1 && map.getOrDefault(max, new HashSet<>()).isEmpty()) max--;
        return map.get(max).stream().findFirst().get();
    }
    
    /** Returns one of the keys with Minimal value. */
	//This is linear time in the worst case
    public String getMinKey() {
        int min=1;
        while(min<max && map.get(min).isEmpty()) min++;
        if(min>max) min=0;
        return map.get(min).stream().findFirst().get();
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */