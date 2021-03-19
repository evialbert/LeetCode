class LFUCache {
    
    private int capacity;
    
    private static class Node {
        Node prev;
        Node next;
        int key;
        int val;
        int freq = 1;
        
        public Node(int key, int val) {
            this.key = key;
            this.val = val;
        }
        
        public Node(int key, int val, Node prev, Node next) {
            this.key = key;
            this.prev = prev;
            this.next = next;
            this.val = val;
        }
    }
    
    Map<Integer, Node> m = new HashMap<>();
    
    Map<Integer, Node> fMap = new HashMap<>();
    
    private Node head;
    private Node tail;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.freq = 0;
        tail.freq = 0;
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if (capacity == 0) return -1;
        if (m.containsKey(key)) {
            Node n = m.get(key);
            updateFreq(n);
            return n.val;
        } else {
            return -1;
        }
    }
    
    public void put(int key, int value) {
        if (capacity == 0) return;
        if (m.containsKey(key)) {
            Node n = m.get(key);
            n.val = value;
            updateFreq(n);
        } else {
            if (m.size() == capacity) {
                evict();
            }
            Node prev;
            Node n = new Node(key, value);
            if (fMap.containsKey(1)) {
                prev = fMap.get(1);
            } else {
                prev = head;
            }
            fMap.put(1, n);
            n.prev = prev;
            n.next = prev.next;
            prev.next = n;
            n.next.prev = n;
            m.put(key, n);
        }
    }
    
    private void evict() {
        Node n = head.next;
        head.next.next.prev = head;
        head.next = head.next.next;
        
        if (fMap.get(n.freq) == n) {
            fMap.remove(n.freq);
        }
        m.remove(n.key);
    }
    
    private void updateFreq(Node n) {
        if (fMap.get(n.freq) == n) {
            // Choose the prev node if possible
            if (n.prev.freq == n.freq) {
                fMap.put(n.freq, n.prev);
            } else {
                fMap.remove(n.freq);
            }
        }
        n.freq++;
        Node prev = n.prev;
        n.prev.next = n.next;
        n.next.prev = n.prev;
        if (fMap.containsKey(n.freq)) {
            prev = fMap.get(n.freq);
        } else {
            if (fMap.containsKey(n.freq - 1)) {
                prev = fMap.get(n.freq - 1);
            }
        }
        fMap.put(n.freq, n);
        n.prev = prev;
        n.next = prev.next;
        prev.next = n;
        n.next.prev = n;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */