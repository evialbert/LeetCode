class Solution {
    
    private Map<List<Integer>, Boolean> cache;

    public boolean[] canMakePalindromeQueries(String s, int[][] queries) {
        cache = new HashMap<>();
        int n = s.length();
        int m = queries.length;
        boolean[] result = new boolean[m];
        Map<Character, Integer> letterAmount = new HashMap<>();
        for (int i = 0; i < n / 2; i++) {
            letterAmount.merge(s.charAt(i), 1, Integer::sum);
            letterAmount.merge(s.charAt(i + n / 2), -1, Integer::sum);
        }
        for (Map.Entry<Character, Integer> entry : letterAmount.entrySet()) {
            if (entry.getValue() != 0) {
                return result;
            }
        }

        for (int i = 0; i < m; i++) {
            result[i] = performQuery(s, queries[i]);
        }
        return result;
    }

    private boolean performQuery(String s, int[] query) {
        List<Integer> key = List.of(query[0], query[1], query[2], query[3]);
        if (cache.containsKey(key)) {
            return cache.get(key);
        }

        int n = s.length();
        int half = s.length() / 2;
        Map<Character, Integer> left = new HashMap<>();
        Map<Character, Integer> right = new HashMap<>();
        Set<Character> letters = new HashSet<>();
        for (int l = 0; l < half; l++) {
            int r = n - l - 1;
            boolean inLeftInterval = l >= query[0] && l <= query[1];
            boolean inRightInterval = r >= query[2] && r <= query[3];
            if (inLeftInterval && inRightInterval) {
                left.merge(s.charAt(l), 1, Integer::sum);
                right.merge(s.charAt(r), 1, Integer::sum);
            } else if (!inLeftInterval && !inRightInterval) {
                if (s.charAt(l) != s.charAt(r)) {
                    cache.put(key, false);
                    return false;
                }
            } else if (inLeftInterval) {
                left.merge(s.charAt(l), 1, Integer::sum);
                left.merge(s.charAt(r), -1, Integer::sum);
            } else {
                right.merge(s.charAt(l), -1, Integer::sum);
                right.merge(s.charAt(r), 1, Integer::sum);
            }
            letters.add(s.charAt(l));
            letters.add(s.charAt(r));
        }

        for (Character letter : letters) {
            int l = left.getOrDefault(letter, 0);
            int r = right.getOrDefault(letter, 0);
            if (l < 0 || r < 0 || l != r) {
                cache.put(key, false);
                return false;
            }
        }
        cache.put(key, true);
        return true;
    }
}