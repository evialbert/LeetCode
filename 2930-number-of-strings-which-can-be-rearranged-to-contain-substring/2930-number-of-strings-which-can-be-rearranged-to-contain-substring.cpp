class Solution {
int mod=(int)(1e9+7);
private:
    int fun(int idx,int mask,int n,vector<vector<int>>&dp){
        if(idx>=n){
            if(mask==((1<<4)-1)){
                return 1;
            }
            return 0;
        }
        if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        int count=0;
        for(char c='a';c<='z';c++){
            if(c=='e'){
                if((mask&(1<<0))==0){
                    count=(count+fun(idx+1,mask|(1<<0),n,dp))%mod;
                }
                else{
                    count=(count+fun(idx+1,mask|(1<<1),n,dp))%mod;
                }
            }
            else if(c=='l'){
                count=(count+fun(idx+1,mask|(1<<2),n,dp))%mod;
            }
            else if(c=='t'){
                count=(count+fun(idx+1,mask|(1<<3),n,dp))%mod;
            }
            else{
                count=(count+fun(idx+1,mask,n,dp))%mod;
            }
        }
        return dp[idx][mask]= count%mod;
    }
public:
    int stringCount(int n) {
        vector<vector<int>>dp(n,vector<int>(1<<5,-1));
        return fun(0,0,n,dp);
        
    }
};