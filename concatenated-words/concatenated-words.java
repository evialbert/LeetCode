class Solution {

    public List<String> findAllConcatenatedWordsInADict(String[] words) {

        if (words.length == 0 || words.length == 1) {
            return new ArrayList<>();
        }
        Set<String> set = new HashSet<>(Arrays.asList(words));
        List<String> result = new ArrayList<>();
        for (String word : words) {
            count = 0;
            set.remove(word);
            if (canBeFormed(word, set) && count > 0) {
                result.add(word);
            }
            set.add(word);
        }
        return result;
    }

    int count = 0;

    Map<String, Boolean> dp = new HashMap<>();

    private boolean canBeFormed(String s,
                                Set<String> set) {

        if (s.isEmpty() || set.contains(s)) {
            return true;
        }
        count++;
        if (dp.containsKey(s)) {
            return dp.get(s);
        }

        for (int i = 1; i < s.length(); i++) {
            String left = s.substring(0, i);
            if (set.contains(left)) {
                boolean isPossible = canBeFormed(s.substring(i), set);
                if (isPossible) {
                    dp.put(s, true);
                    return true;
                }
            }
        }
        dp.put(s, false);
        return false;
    }
}
