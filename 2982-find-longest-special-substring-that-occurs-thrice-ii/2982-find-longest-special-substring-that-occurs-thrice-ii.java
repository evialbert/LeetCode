class Solution {
    public static int maximumLength(String s) {
        int n = s.length();
        int ans = -1;
        Map<String, Integer> map = new HashMap<>();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                j++;
            }
            int len = j - i;
            int num = len;
            for (int k = 1; k <= len; k++) {
                String sub = s.charAt(i) + "" + k;
                map.put(sub, map.getOrDefault(sub, 0) + len - (k - 1));
            }
            i = j;
        }
        
        for (String str: map.keySet()) {
            if (map.get(str) >= 3) {
                String count = str.substring(1);
                ans = Math.max(ans, Integer.valueOf(count));
            }
        }
        return ans;
    }

}