class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        vector<vector<int> > peop(50);
        for(int i=0;i<hats.size();i++){
            for(auto h:hats[i]){
                peop[h].push_back(i);  //  peop[i] contains the persons which likes i(1...40) id hat..
            }
        }
        int m=1e9+7;
        vector<int> dp((1<<n)+1);
        dp[0]=1;
        for(int i=1;i<=40;i++){
            for(int j=(1<<n)-1;j>=0;j--){
                for(auto p:peop[i]){
                    
                    if((j & (1<<p))==0){  //  if in current mask the pth person is not wearing hat so we can give current hat i to that person...
                        dp[j|(1<<p)]+=dp[j];  //  so add ways dp[j] in ways to wear diffrent hats in mask (j | (1<<p))
                        dp[j|(1<<p)]%=m;  
                    }
                    
                }
            }
        }
        for(auto d:dp){
            cout<<d<<" ";
        }
        return dp[(1<<n)-1];// returning answer dp[(1<<n)-1] which is to wear diffrent hats to n persons..
    }
};