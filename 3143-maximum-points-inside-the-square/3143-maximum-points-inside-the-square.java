class Solution {
    public int maxPointsInsideSquare(int[][] points, String s) {
        char[] arr = s.toCharArray();
        int n = points.length, discard = Integer.MAX_VALUE, max = -1, x = 0;
        int[] freq = new int[26];
        Arrays.fill(freq, discard);
        for (int i = 0; i < n; i++) {
            x = Math.max(Math.abs(points[i][0]), Math.abs(points[i][1]));
            if (freq[arr[i] - 97] == 0) {
                freq[arr[i] - 97] = x;
            } else if (freq[arr[i] - 97] > x) {
                discard = Math.min(discard, freq[arr[i] - 97]);
                freq[arr[i] - 97] = x;
            } else 
                discard = Math.min(discard, x);
        }
        max = 0;
        x = 0;
        for (int i : freq)
            if(i < discard && max < i) max = i;
        for(int i : freq) if(i>=0 && i<=max) x++;
        return x;
    }
}