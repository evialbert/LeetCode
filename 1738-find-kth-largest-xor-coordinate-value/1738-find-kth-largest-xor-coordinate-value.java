class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] pxor = new int[m + 1][n + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return a-b; 
        });
        for (int a = 1; a<=m; a++) {
            for (int b = 1; b<=n; b++) {
                pxor[a][b] = pxor[a][b-1] ^ pxor[a-1][b] ^ pxor[a-1][b-1] ^ matrix[a-1][b-1];
                if (pq.size()<k) pq.add(pxor[a][b]);
                else {
                    if (pq.peek()<pxor[a][b]) {
                        pq.poll();
                        pq.add(pxor[a][b]);
                    }
                }
            }
        }
        return pq.poll();
    }
}