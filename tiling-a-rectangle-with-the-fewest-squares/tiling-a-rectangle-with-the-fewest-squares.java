class Solution {
    public int tilingRectangle(int n, int m) {
        if (n > m) return tilingRectangle(m, n);
        return calc(n, m, new int[n+1][m+1]);
    }
    
    int calc(int n, int m, int[][] cache) {
        if (n > m) return calc(m, n, cache);
        if (n == 0) return 0;
        if (n == m) return 1;
        if (n == 1) return m;
        if (cache[n][m] > 0) return cache[n][m];
        int count = Integer.MAX_VALUE;
        int maxSize = Math.min(m, n);
        for (int size=1; size<=maxSize; size++) {
            // two ways of dividing via 1 square + 2 rectangles.
            count = Math.min(count, 
                1 + calc(n-size, m, cache) + calc(size, m-size, cache));
            count = Math.min(count, 
                1 + calc(n, m-size, cache) + calc(n-size, size, cache));
            // ways of dividing via 2 squares + 3 rectangles.
            for (int size2=n-size+1; size2<m-size && size2<n; size2++) {
                count = Math.min(count, 2 + calc(n-size, m-size2, cache)
                    + calc(n-size2, m-size, cache) +
                    + calc(size+size2-n, m-size-size2, cache));
            }
        }
        cache[n][m] = count;
        return count;
    }
}