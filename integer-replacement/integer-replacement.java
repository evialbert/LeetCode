class Solution {
    public int integerReplacement(int n) {
        if (n == Integer.MAX_VALUE) return 32;
        return ops(n);
    }
    public int ops(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return 1 + ops(n/2);
        return 1 + Math.min(ops(n+1), ops(n-1));
    }
}