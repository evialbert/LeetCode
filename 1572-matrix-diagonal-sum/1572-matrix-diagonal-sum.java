class Solution {
    public int diagonalSum(int[][] mat) {
        if(mat.length==1)
            return mat[0][0];
        int sum=0;
        for(int i=0;i<mat.length;i++){
            sum+=mat[i][i]+mat[i][mat.length-1-i];
            if(i==mat.length-1-i){
                sum-=mat[i][mat.length-1-i];
            }
        }
        return sum; 
    } 
}