class Solution {
    public boolean isPossibleToRearrange(String s, String t, int k) {
        int increment = s.length() / k;
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i = i + increment) {
            String subStr = s.substring(i, i + increment);
            map.put(subStr, map.getOrDefault(subStr, 0) + 1);
        }
        for (int i = 0; i < t.length(); i = i + increment) {
            String subStr = t.substring(i, i + increment);
            if (!map.containsKey(subStr)) {
                return false;
            }
            map.put(subStr, map.getOrDefault(subStr, 0) - 1);
            if (map.get(subStr) == 0) {
                map.remove(subStr);
            }
        }
        return true;
    }
}