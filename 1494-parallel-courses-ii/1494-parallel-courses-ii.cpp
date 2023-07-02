class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dep, int k) {
        vector<int> pre(n);
        
        for(int i=0;i<dep.size();i++){
            int x=dep[i][0]-1;
            int y=dep[i][1]-1;
            
            pre[y]|=(1<<x);
        }
        
        vector<int> dp(1<<n,n);
        
        dp[0]=0;
        
        for(int i=0;i<(1<<n);i++){
            int ex=0;
            
            for(int j=0;j<n;j++){
                if((pre[j]&i)==pre[j]){
                    ex|=(1<<j);
                }
            }
            
            ex&=(~i);
            
            // enumerate all subset of ex which have size less than k
            // https://cp-algorithms.com/algebra/all-submasks.html
            for(int s=ex;s;s=(s-1)&ex){
                if(__builtin_popcount(s)<=k){
                    dp[i|s]=min(dp[i|s],dp[i]+1);
                }
            }
        }
        
        return dp.back();
    }
};