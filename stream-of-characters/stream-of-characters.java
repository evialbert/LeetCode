class StreamChecker {
    Trie root;
    
    public StreamChecker(String[] words) {
        root = new Trie();
        root.build(words);
    }
    
    public boolean query(char letter) {
        return root.search(letter);
    }
}

    public class Trie {
        HashMap<Character, Trie> index;
        List<Trie> searchPointers;
        boolean isWord;
        
        public Trie() {
            this.index = new HashMap();
            this.isWord = false;
        }
        
        public void build(String[] words) {
            Trie root = this;
            for(String word : words) {
                Trie t = root;
                for(int i=0;i<word.length();i++){
                    t = t.index.computeIfAbsent(word.charAt(i), x -> new Trie());
                }
                t.isWord = true;
            }
        }
        
        public boolean search(char letter) {
            boolean ans = false;
            List<Trie> nextSearchPointers = new ArrayList<Trie>();
            nextSearchPointers.add(this);
            if(this.searchPointers == null) { this.searchPointers = new ArrayList(); searchPointers.add(this); }            
            for(Trie t : this.searchPointers) {
                Trie nextTrie = t.index.getOrDefault(letter, null);
                if(nextTrie != null && nextTrie.isWord) { ans=true; }
                if(nextTrie != null) { nextSearchPointers.add(nextTrie); }
            }
            
            this.searchPointers = nextSearchPointers;
            return ans;
        }
    }