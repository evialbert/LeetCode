class Solution {
    public int prefix[];

    public int func(int i,int k,int currtime, int[] position, int[] time,int[][][]dp){
        int n=position.length;
        if(i==n-1 && k>0){
            return (int)1e9;
        }

        if(i==n-1){
            return 0;
        }
        

        if(dp[i][k][currtime]!=(int)1e9){
            return dp[i][k][currtime];
        }

        // not do operation

        int ans=(int)1e9;

        ans=Math.min(ans, currtime*( position[i+1]-position[i] ) + func(i+1,k,time[i+1],position,time,dp) );

        // do j merge op
        
        for(int j=1;j<=k;j++){
            if(i+j+1>=n){
                break;
            }
            ans=Math.min(ans, currtime*(position[i+j+1]-position[i]) + func( i+j+1,k-j, prefix[i+j+1]-prefix[i],position,time,dp )  );
        }

        return dp[i][k][currtime]=ans;
        
    }
    
    public int minTravelTime(int l, int n, int k, int[] position, int[] time) {
        prefix=new int[n];
        prefix[0]=time[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+time[i];
        }

        int[][][]dp=new int[n+1][k+1][101];

        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int m=0;m<=100;m++){
                    dp[i][j][m]=(int)1e9;
                }
            }
        }

        return func( 0,k,time[0],position,time ,dp);
        
    }
}