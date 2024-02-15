class WordDictionary {

    private Set<String> dic;
    private Deque<String> queue;

    public WordDictionary() {
        this.dic = new HashSet<>();
        this.queue = new ArrayDeque<>();
    }
    
    public void addWord(String word) {
        dic.add(word);
    }
    
    public boolean search(String word) {
        queue.clear();
        queue.offer(word);
        while(!queue.isEmpty()) {
            String cur = queue.poll();
            int dotIndex = cur.indexOf(".");
            if(dotIndex == -1) {
                if(dic.contains(cur)) return true;
            } else {
                String replace;
                for(int i = 0; i < 26; i++) {
                    char dotReplace = (char) ('a' + i);
                    replace = cur.substring(0, dotIndex) + dotReplace + cur.substring(dotIndex+1, cur.length());
                    queue.offer(replace);
                }
                 
            }
        }


        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */