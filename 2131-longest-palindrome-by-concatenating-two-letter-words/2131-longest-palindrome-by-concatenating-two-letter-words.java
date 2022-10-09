class Solution {

    public int longestPalindrome(String[] words) {
        HashMap<String, Integer> map = new HashMap<>();
        int max = 0;
        for (int i = 0; i < words.length; i++) {
            String rev = words[i].charAt(1) + "" + words[i].charAt(0);
            if (map.containsKey(rev)) {
                max += 4;
                map.put(rev, map.get(rev) - 1); // decrease its count as we won't be taking it again
                if (map.get(rev) == 0) map.remove(rev);
                continue; // as we also won't be taking current string again
            }
            map.put(words[i], map.getOrDefault(words[i], 0) + 1);
        }
        for (String k : map.keySet()) {
            if (map.get(k) == 1 && (k.charAt(1) + "" + k.charAt(0)).equals(k)) {
                max += 2;
                break;
            }
        }
        return max;
    }
}