class Solution {
public:
    void dfs(int s,int n,vector<int>&vis,vector<vector<int>>& isConnected){
        vis[s]=1;
        vector<int>adj;
        for(int i=0;i<n;i++){
            int x=isConnected[s][i];
            if(x==1){
                adj.push_back(i);
            }
        }
        for(auto x:adj){
            if(vis[x]==0){
                dfs(x,n,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n= isConnected.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,n,vis,isConnected);
            }
        }
        return ans;
    }
};
