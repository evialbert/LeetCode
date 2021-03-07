class RandomizedSet {
    Map<Integer,Integer> map = new HashMap<Integer,Integer>();
    Object[] set = new Object[100];
    int size = 0;
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (map.containsKey(val)) return false;
        
        if (size == set.length) {
            Object[] newset = new Object[size*2];
            System.arraycopy(set, 0, newset, 0, size);
            set = newset;
        }
        set[size] = val;
        map.put(val, size);
        size += 1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!map.containsKey(val)) return false;
        int i = map.get(val);
        
        if (i != size-1) {
            int last = (int) set[size-1];
            set[i] = last;
            map.put(last, i);
        }
        set[size-1] = null;
        map.remove(val);
        size -= 1;
        
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random rand = new Random();
        int i = rand.nextInt(size);
        return (int) set[i];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */