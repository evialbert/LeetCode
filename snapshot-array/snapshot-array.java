class SnapshotArray {
    private int snapId = 0;
    Map<String, Integer> array = new HashMap<>();
    private int len = 0;
    public SnapshotArray(int length) {
        this.len = length;
    }
    
    public void set(int index, int val) {
        if (index < len) {
            array.put(snapId+":"+index, val);
        }
    }
    
    public int snap() {
        return snapId++;
    }
    
    public int get(int index, int snap_id) {
        for (int i = snap_id; i >=0; i--) {
            String key = i+":"+index;
            if (array.containsKey(key)) {
                return array.get(key);
            }
        }
        
        return 0;
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */