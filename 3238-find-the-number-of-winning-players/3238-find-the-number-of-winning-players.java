class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int res = 0;
        int[][] arr = new int[n][11];
        for (int[] p : pick)
            arr[p[0]][p[1]]++;
        //System.out.println(Arrays.deepToString(arr));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 11; j++) 
                if (arr[i][j] >= i + 1) {
                    res++;
                    break;
                }
        return res;
    }
}