class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int len) {
        int n=floor.size();
        int x=numCarpets;
        floor='#'+floor;//so that ith row of dp matches with the ith character
        vector<vector<int>> dp(n+1,vector<int>(x+1,0));
        dp[0][0]=0;
        for(int i=0;i<=x;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0]+(floor[i]=='1');
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=x;j++){
                if(j>=1){
				//if we have atleast 1 carpet or even more
				//then we can use
				//however before usuing at i also check if i-len>=0
                    if(i-len>=0){
                        dp[i][j]=min(dp[i-len][j-1],dp[i-1][j]+(floor[i]=='1'));
                    }
                }
                else{
				//if we do not have any carpet
                    dp[i][j]=dp[i-1][j]+(floor[i]=='1');
                }
            }
        }
        return dp[n][x];
    }
};