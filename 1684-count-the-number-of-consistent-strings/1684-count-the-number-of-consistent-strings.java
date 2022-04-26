   class Solution {
        public int countConsistentStrings(String allowed, String[] words) {
            int result = words.length;
            for (int i = 0; i < words.length; i++) {
                for (int k = 0; k < words[i].length(); k++) {
                    if (!allowed.contains(String.valueOf(words[i].charAt(k)))) {
                        result--;

                        break;
                    }
                }
            }
            return result;
        }
    }