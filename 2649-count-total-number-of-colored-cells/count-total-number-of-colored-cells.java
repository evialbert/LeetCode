class Solution {
    public long coloredCells(int n) {
        // 1 + 4 + 8 + 12 ...
        // 1 + n/2 * (8 + (n-1)*4)
        n--;
        return 1 + ((n)*(8L + 4L*(n-1L))) / 2L;
    }
}