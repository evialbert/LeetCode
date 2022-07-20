class Solution {
    public int maximumWealth(int[][] accounts) {
        int wealth = 0;
        for(int[] account : accounts){
            int sum = 0;
            for(int money : account){
                sum = sum + money;
            }
            wealth = Math.max(wealth, sum);
        }
        return wealth;
    }
}