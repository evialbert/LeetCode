class TrieNode {
    Map<Character, TrieNode> childs = new HashMap<>();
    int weight = 0;
    
    TrieNode() {}
}

class WordFilter {
    TrieNode trie;
    
    public WordFilter(String[] words) {
        trie = new TrieNode();
        int wt = 0;
        for (String word: words) {
            String newWord = "{" + word;
            add(newWord, wt);
            
            for (int j = word.length() - 1; j >= 0; j--) {
                newWord = word.charAt(j) + newWord;
                add(newWord, wt);
            }
            wt++;
        }
    }
    
    public void add(String word, int weight) {
        TrieNode node = trie;
        
        for (char ch: word.toCharArray()) {
            if (!node.childs.containsKey(ch))
                node.childs.put(ch, new TrieNode());
            
            node = node.childs.get(ch);
            node.weight = weight;
        }
    }
    
    public int f(String prefix, String suffix) {
        TrieNode node = trie;
        
        for (char ch: (suffix + "{" + prefix).toCharArray()) {
            if (!node.childs.containsKey(ch))
                return -1;
            
            node = node.childs.get(ch);
        }
        
        return node.weight;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */