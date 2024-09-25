class Solution {

     class TrieNode {
        TrieNode[] children;
        int count;  // Count of words passing through this node

        public TrieNode() {
            this.children = new TrieNode[26];  // Array for 26 lowercase letters
            this.count = 0;
        }
    }

    // Trie class to manage the Trie structure
    class Trie {
        TrieNode root;

        public Trie() {
            root = new TrieNode();
        }

        // Insert a word into the Trie
        public void insert(String word) {
            TrieNode node = root;
            for (char ch : word.toCharArray()) {
                int index = ch - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
                node.count++;  // Increment count at each node
            }
        }

        // Get the prefix score for a given word
        public int getPrefixScore(String word) {
            TrieNode node = root;
            int score = 0;
            for (char ch : word.toCharArray()) {
                int index = ch - 'a';
                node = node.children[index];
                score += node.count;  // Add count to the score for each prefix
            }
            return score;
        }
    }


    public int[] sumPrefixScores(String[] words) {
         Trie trie = new Trie();  // Initialize the Trie
        int n = words.length;
        int[] result = new int[n];  // Result array to store the prefix scores

        // Insert all words into the Trie
        for (String word : words) {
            trie.insert(word);
        }

        // Compute the prefix scores for each word
        for (int i = 0; i < n; i++) {
            result[i] = trie.getPrefixScore(words[i]);
        }

        return result;  // Return the result array
    }
}