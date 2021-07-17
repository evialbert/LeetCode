/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    private Map<String, Integer> probs;

    public void findSecretWord(String[] wordlist, Master master) {
        probs = new HashMap<>();

        for (String word : wordlist) {
            probs.put(word, 0);
        }

        int matches = 0;
        int guessed = 0;
        while (matches != 6 && guessed < 10) {
            String word = pollWord();
            matches = master.guess(word);
            calcWeights(word, matches);
            guessed ++;
        }
    }
    
    private void calcWeights(String word, int matches) {
        for (String w : probs.keySet()) {
            int n = 0;
            for (int i = 0; i < word.length(); i ++) {
                if (word.charAt(i) == w.charAt(i))
                    n ++;
            }
            if (n == matches)
                probs.put(w, probs.getOrDefault(w, 0) + 1);
        }
    }
    
    private String pollWord() {
        Map.Entry<String, Integer> entry = probs.entrySet().stream()
            .max(Comparator.comparing(Map.Entry::getValue))
            .get();
        probs.remove(entry.getKey());
        return entry.getKey();
    }
}