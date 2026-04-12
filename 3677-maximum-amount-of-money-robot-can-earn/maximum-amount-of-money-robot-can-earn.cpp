class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        int dp[n][m][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=coins[i][j];
                if(i==0 && j==0){
                    dp[0][0][0]=dp[0][0][1]=dp[0][0][2]=val;
                    if(val<0){
                        dp[0][0][1]=0;
                        dp[0][0][2]=0;
                    }
                }
                else if(i==0){
                    dp[i][j][0]=val+dp[i][j-1][0];
                    dp[i][j][1]=max(val+dp[i][j-1][1],0+dp[i][j-1][0]);
                    dp[i][j][2]=max(val+dp[i][j-1][2],0+dp[i][j-1][1]);
                }
                else if(j==0){
                    dp[i][j][0]=val+dp[i-1][j][0];
                    dp[i][j][1]=max(val+dp[i-1][j][1],0+dp[i-1][j][0]);
                    dp[i][j][2]=max(val+dp[i-1][j][2],0+dp[i-1][j][1]);
                }
                else{
                    
                    dp[i][j][0]=max(val+dp[i-1][j][0],val+dp[i][j-1][0]);

                    int left1=max(val+dp[i][j-1][1],0+dp[i][j-1][0]);
                    int top1=max(val+dp[i-1][j][1],0+dp[i-1][j][0]);
                    dp[i][j][1]=max(left1,top1);
                    int left2=max(val+dp[i][j-1][2],0+dp[i][j-1][1]);
                    int top2=max(val+dp[i-1][j][2],0+dp[i-1][j][1]);
                    dp[i][j][2]=max(left2,top2);
                }
            }
        }
        //cout<<dp[n-1][m-1][0]<<" "<<dp[n-1][m-1][1]<<" "<<dp[n-1][m-1][2];
        return dp[n-1][m-1][2];
    }
};