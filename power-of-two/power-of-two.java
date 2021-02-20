class Solution {
    public boolean isPowerOfTwo(int n) {

        if (n <= 0) return false;

        n = n & (n - 1); // should only have one bit that is 1.

        return n == 0;

    }
}