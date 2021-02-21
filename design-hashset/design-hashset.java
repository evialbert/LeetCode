class MyHashSet {
    private List<LinkedList<Integer>> list;
    private int size = 13;

    /**
     * Initialize your data structure here.
     */
    public MyHashSet() {
        list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(new LinkedList<>());
        }
    }

    public void add(int key) {
        if (!contains(key)) list.get(key % size).add(key);
    }

    public void remove(int key) {
        if (contains(key)) list.get(key % size).removeFirstOccurrence(key);
    }

    /**
     * Returns true if this set contains the specified element
     */
    public boolean contains(int key) {
        LinkedList<Integer> bucket = list.get(key % size);
        for (int num : bucket) if (num == key) return true;
        return false;
    }
}


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */