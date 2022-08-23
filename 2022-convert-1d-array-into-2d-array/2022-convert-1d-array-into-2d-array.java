class Solution {
    public int[][] construct2DArray(int[] arr, int m, int n) {
        if (arr.length != m*n) return new int[0][0];
        int[][] ans = new int[m][n];

        int a = 0, b = 0, c = 0;
        for (int i : arr){
            c++;
            ans[a][b++] = i;
            if (c % n == 0) {
                a++;
                b = 0;
            }
        }

        return ans;
    }
}