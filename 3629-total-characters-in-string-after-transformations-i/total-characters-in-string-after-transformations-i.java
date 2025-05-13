class Solution {
    public int lengthAfterTransformations(String s, int t) {
        long mod = 1_000_000_007;
        long[] a = new long[26];
        for (char c : s.toCharArray()) a[c - 'a']++;

        while (t-- > 0) {
            long[] b = new long[26];
            b[0] = a[25];
            b[1] = a[25];
            for (int i = 0; i < 25; i++){ 
                b[i+1] = (b[i+1]+a[i]) % mod;
            }
            a = b;
        }

        long res = 0;
        for (long x : a) res = (res + x) % mod;
        return (int) res;
    }
}