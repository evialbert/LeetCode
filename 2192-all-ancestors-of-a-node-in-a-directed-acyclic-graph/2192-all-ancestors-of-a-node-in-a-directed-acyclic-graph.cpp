class Solution 
{
public:

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> g(n);
        vector<vector<int>>ans(n);
        
        for(auto &i:edges)
        {
             g[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++){
            dfs(g,ans,i, i);
        }
        return ans;
    }
    
    void dfs(vector<vector<int>> &g,vector<vector<int>> &ans,int src, int anc)
    {
        for(auto &it : g[src])
        {
            if(ans[it].size()==0 || ans[it].back()!=anc)
            {
                ans[it].push_back(anc);
                dfs(g,ans,it,anc);
            }
        }
    }
};