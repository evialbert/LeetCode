class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length();
        int[] d = new int[n];
        for (int i = 0; i < n; i++) d[i] = s.charAt(i) - '0';
        while (n > 2) {
            for (int i = 0; i < n - 1; i++) d[i] = (d[i] + d[i + 1]) % 10;
            n--;
        }
        return d[0] == d[1];
    }
}