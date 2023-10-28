class Solution {
    public int countVowelPermutation(int n) {
        long mod = 1_000_000_000 + 7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int pos = n - 1; pos >= 1; --pos) {
            long na = a, ne = e, ni = i, no = o, nu = u;
            a = ne;
            e = (na + ni) % mod;
            i = (na + ne + no + nu) % mod;
            o = (ni + nu) % mod;
            u = na;
        }
        return (int) ((a + e + i + o + u) % mod);
    }
}