class MagicDictionary {
    public class TrieNode {
        Map<Character, TrieNode> nodes;
        Boolean endsHere;
        
        public TrieNode() {
            this.nodes = new HashMap<>();
            this.endsHere = false;
        }
    }
    
    TrieNode root;

    /** Initialize your data structure here. */
    public MagicDictionary() {
        this.root = new TrieNode();
    }
    
    public void buildDict(String[] dictionary) {
        for (String word : dictionary) {
            TrieNode node = this.root;
            for (Character c : word.toCharArray()) {
                if(!node.nodes.containsKey(c)) {
                    node.nodes.put(c, new TrieNode());
                }
                node = node.nodes.get(c);
            }
            node.endsHere = true;
        }
    }
    
    public boolean search(String searchWord) {
        return searchUtil(this.root, searchWord, false);
    }
    
    private boolean searchUtil(TrieNode node, String searchWord, Boolean replaced) {
        if(searchWord.length() == 0) return node.endsHere && replaced;
        if (replaced) {
            if (!node.nodes.containsKey(searchWord.charAt(0))) {
                return false;
            }
            return searchUtil(node.nodes.get(searchWord.charAt(0)), searchWord.substring(1), replaced);
        } else {
            Boolean result = false;
            for (Character c : node.nodes.keySet()) {
                result = result || searchUtil(node.nodes.get(c), searchWord.substring(1), c != searchWord.charAt(0));
            }
            return result;
        }
    }    
}
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */