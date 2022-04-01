class Solution {
    public int countVowelStrings(int n) {
        int[][] solution = new int[n+1][6];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=5;j++) {
                solution[i][j] = (i>1 ? solution[i-1][j] : 1) + solution[i][j-1];
            }
        }
        return solution[n][5];
    }
}