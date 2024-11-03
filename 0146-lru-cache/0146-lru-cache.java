class LRUCache {

    private final Map<Integer, Integer> nodes;

    public LRUCache(int capacity) {
        this.nodes = new LinkedHashMap<>(capacity, 0.75f, true) {
            @Override
            protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
                return size() > capacity;
            }
        };
    }

    public int get(int key) {
        return Objects.requireNonNullElse(this.nodes.get(key), -1);
    }

    public void put(int key, int value) {
        this.nodes.put(key, value);
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */