class Solution {
    public String[] createGrid(int m, int n){
        String[] mat = new String[m];
        for(int i = 0 ; i < m  ; i++){
            mat[i] = new String(".");
            for(int j = 0 ; j < n - 1 ; j++){
                if(i == m - 1) mat[i] = mat[i] +".";
                else
                mat[i] = mat[i]+"#";
            }
        }
        return mat;
    }
}