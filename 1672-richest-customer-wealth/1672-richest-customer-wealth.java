class Solution {
    public int maximumWealth(int[][] accounts) {
        int sum = 0, maxSum = 0;
        
        for(int[] i : accounts){
            for(int j : i){
                sum +=j;
            }
            maxSum = Math.max(maxSum, sum);
            sum = 0;
        }
        return maxSum;
        
    }
}