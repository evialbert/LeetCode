class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        if (words == null || words.length == 0) {
            return 0;
        }

        Set<String> set = new HashSet<>();
        String[] chars = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
        for (String word : words) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < word.length(); i++) {
                sb.append(chars[word.charAt(i) - 'a']);
            }

            set.add(sb.toString());
        }

        return set.size();
    }
}