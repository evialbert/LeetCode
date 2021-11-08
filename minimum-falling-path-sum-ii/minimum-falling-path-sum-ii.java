class Solution {
    
    public int minFallingPathSum(int[][] arr) {
        for(int i=arr.length-2; i>=0; i--){
            for(int j=0; j<arr[0].length; j++){
                int min= Integer.MAX_VALUE;
                for(int k=0; k<arr[0].length; k++){
                    if(k==j) continue;
                    min= Math.min(min,arr[i+1][k]);
                }
                arr[i][j]+= min;
            }
        }
        int ans= arr[0][0];
        for(int i=1; i<arr[0].length; i++) ans= Math.min(ans,arr[0][i]);
        return ans;
    }
}