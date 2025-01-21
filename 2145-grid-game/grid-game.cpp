class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n=grid[0].size();
        vector<long long>pre1(n,0);
        pre1[n-1]=grid[0][n-1];
        vector<long long>pre2(n,0);
        pre2[0]=grid[1][0];
        for(int i=1;i<n;i++){
            pre2[i]+=grid[1][i]+pre2[i-1];
        }

        for(int i=n-2;i>=0;i--){
            pre1[i]+=pre1[i+1]+grid[0][i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long curr=0;
            long long curr2=0;
            if(i+1<n){
                curr2=pre1[i+1];
            }
            if(i-1>=0){
                curr=pre2[i-1];
            }
            ans=min(ans,max(curr,curr2));
        }
        return ans;
    }
};