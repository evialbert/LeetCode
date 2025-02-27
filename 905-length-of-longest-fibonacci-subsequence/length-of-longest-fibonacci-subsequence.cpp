class Solution {
public:
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(n,2));
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
            for(int j=0;j<n;j++){
                int prev=arr[i]-arr[j];
                if(mp.count(prev) && mp[prev]<j){
                    dp[i][j]=1+dp[j][mp[prev]];
                }
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi==2 ? 0:maxi;
    }
};