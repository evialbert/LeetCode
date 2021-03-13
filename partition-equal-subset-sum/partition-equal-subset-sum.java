class Solution {
    public boolean canPartition(int[] nums) {
        int n=nums.length,sum=Arrays.stream(nums).reduce(0,Integer::sum);    
        if((sum&1)==1) return false;
        //DP table,values as rows & required_sum as columns
        boolean[][] memo=new boolean[1+n][1+sum/2];
        //Sum=zero, can be made by not including any value
        for(int i=0;i<=n;i++) memo[i][0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                //Check if sum can be made by including or by excluding current value
                if(nums[i-1]<=j) memo[i][j]=memo[i-1][j-nums[i-1]] | memo[i-1][j];
                else memo[i][j]=memo[i-1][j];
            }
            if(memo[i][sum/2]) return true;
        }
        return false;
    }
}