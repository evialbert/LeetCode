class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] mem = new int[n+1][];
        for(int i=0; i<=n; i++){
            mem[i] = new int[i+1];
            for(int j=0; j<=i; j++)
                mem[i][j] = -1;
        }
        return dp(triangle, n-1, 0, 0, mem);
    }
    int dp(List<List<Integer>> triangle, int n, int i, int j, int[][] mem){
        if(i == n){
            return triangle.get(i).get(j);
        }
        if(mem[i][j] != -1)
            return mem[i][j];
        int min = dp(triangle, n, i+1, j, mem);
        if(min > dp(triangle, n, i+1, j+1, mem))
            min = dp(triangle, n, i+1, j+1, mem);
        return mem[i][j] = triangle.get(i).get(j) + min;
    }
}