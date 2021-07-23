class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> res = new ArrayList<>();
        
        for (String word: words) {
            Map<Character, Character> map = new HashMap<>();
            Set<Character> used = new HashSet<>();
            int i = 0;
            for (i = 0; i < word.length(); i++) {
                char cw = word.charAt(i);
                char cp = pattern.charAt(i);
                if (map.containsKey(cw)) {
                    char mw = map.get(cw);
                    if (cp != mw) break;
                } else {
                    if (used.contains(cp)) break;
                    map.put(cw, cp);
                    used.add(cp);
                }
            }
            if (i == word.length()) res.add(word);
        }
        return res;
    }
}