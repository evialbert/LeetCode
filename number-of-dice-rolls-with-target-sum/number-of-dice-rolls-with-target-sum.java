class Solution {
    int MOD = 1000000000 + 7;
	public int numRollsToTarget(int d, int f, int target) {
	
    int[][] dp=new int[d+1][target+1];
    for (int[] row : dp){
        Arrays.fill(row, 0);
    }
    return rolls(d,f,target,dp);
}

public int rolls(int d,int f,int target,int[][] dp){
    if(target<d)
        return 0;
    if(target>d*f)
        return 0;
    if(d==0 && target==0)
        return 1;
    if(dp[d][target]==0 ){
    for(int i=1;i<=f;i++){
        dp[d][target]=(dp[d][target]+rolls(d-1,f,target-i,dp))%MOD;
    }}
      return (dp[d][target]);
}}