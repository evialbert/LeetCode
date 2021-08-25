class Solution {
    int dp[][];
    public int countTriplets(int[] A) {
        int M=0;
        for(int i : A)M=Math.max(M,i);
        dp=new int[M+1][3];
        for(int i=0;i<dp.length;i++)Arrays.fill(dp[i],-1);
        int res=0;
        for(int i:A){
            res+=dfs(A,i,0);
        }
        return res;
    }
    
    public int dfs(int A[],int cur,int level){
        if(level==2){
            if(cur!=0)return 0;
            return 1;
        }
        if(dp[cur][level]!=-1)return dp[cur][level];
        int res=0;
        for(int n:A){
            res+=dfs(A,cur&n,level+1);
        }
        
        dp[cur][level]=res;
        return res;
    }
}