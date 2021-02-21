class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        int L = A.length;
        for (int i = L - 1; i >= 2; i--) {
            int a = A[i-2];
            int b = A[i-1];
            int c = A[i];
            if (c < a + b) {
                return a + b + c;
            }
        }
        return 0;
    }
}