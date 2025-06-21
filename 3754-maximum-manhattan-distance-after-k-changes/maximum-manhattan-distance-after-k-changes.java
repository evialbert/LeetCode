class Solution {
    public int maxDistance(String st, int k) {
        int n = 0, s = 0, e = 0, w = 0;
        int max = 0;
       
        for (char c : st.toCharArray()) {
            if (c == 'N') {
                n++;
            } else if (c == 'S') {
                s++;
            } else if (c == 'E') {
                e++;
            } else {
                w++;
            }
            max = Math.max(max, n + e - w - s + 2 * Math.min(s + w, k));
            max = Math.max(max, n + w - s - e + 2 * Math.min(s + e, k));
            max = Math.max(max, s + e - n - w + 2 * Math.min(n + w, k));
            max = Math.max(max, s + w - n - e + 2 * Math.min(n + e, k));
        }

        return max;
    }
}