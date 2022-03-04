class Solution {
    public int numSpecial(int[][] mat) {
        int[][] cache = new int[Math.max(mat.length, mat[0].length)][2];
        for(int i =0; i< mat.length; ++i) {
            for(int j =0; j< mat[0].length; ++j) {
                if(mat[i][j] == 1) {
                    cache[i][0]++;
                    cache[j][1]++;
                }
            }
        }
        int res = 0;
        for(int i =0; i < mat.length; ++i) {
            for(int j =0; j< mat[0].length; ++j) {
                if(mat[i][j] == 1 && cache[i][0] == 1 && cache[j][1] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
}