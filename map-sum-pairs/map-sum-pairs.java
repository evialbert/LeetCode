class MapSum {
    class TrieNode {
       char c;
       HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
       int val;
       public TrieNode(char c){
           this.c = c;
           this.val = 0;
       }
    }
    private TrieNode root;
    /** Initialize your data structure here. */
    public MapSum() {
        root = new TrieNode(' ');
    }
    
    public void insert(String key, int val) {
        TrieNode node = root;
        char[] cs = key.toCharArray();
        for(char c : cs) {
            if (node.children.containsKey(c)) {
                node = node.children.get(c);
            } else {
                TrieNode cur = new TrieNode(c);
                node.children.put(c, cur);
                node = cur;
            }
        }
        node.val = val;
    }
    
    public int sum(String prefix) {
        TrieNode node = root;
        char[] cs = prefix.toCharArray();
        for (char c : cs) {
            if (node.children.containsKey(c)) {
                node = node.children.get(c);
            } else {
                return 0;
            }
        }
        return countSum(node);
    }
    
    private int countSum(TrieNode node) {
        int count = 0;
        count += node.val;
        for (TrieNode n : node.children.values()) {
            count += countSum(n);
        }
        return count;
    }
}
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */