class Solution {
    long dp[][][];
    int mod=1000000007;
    public int profitableSchemes(int G, int P, int[] group, int[] profit) {
        dp=new long[group.length+1][G+1][P+1];
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<dp[0].length;j++)Arrays.fill(dp[i][j],-1);
        }
        return (int)(dfs(group,profit,0,G,P));
    }
    
    public long dfs(int[] group, int[] profits,int index,int G,int P){
        if(index>=group.length){
            if(P==0)return 1;
            return 0;
        }
        if(dp[index][G][P]!=-1)return dp[index][G][P];
        int people=group[index];
        int profit=profits[index];
        long res=0;
        res+=dfs(group,profits,index+1,G,P);
        if(G>=people){
           res+=dfs(group,profits,index+1,G-people,Math.max(0,P-profit)); 
        }
        res%=mod;
        dp[index][G][P]=res;
        return res;
    }
}