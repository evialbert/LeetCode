class Solution {
public:
    void dfs(vector<int>adj[],int node,vector<int>&visit,int &ans,int count,vector<int>&path){
        visit[node]=1;
        path[node]=count;
        for(int i=0;i<adj[node].size();++i){
            if(visit[adj[node][i]]==0)
               dfs(adj,adj[node][i],visit,ans,count+1,path);
            else if(path[adj[node][i]]!=0)
               ans=max(ans,abs(count-path[adj[node][i]])+1);
        }
        path[node]=0;
        return ;
    }
    int longestCycle(vector<int>& e) {
        int n=e.size();
        vector<int>adj[n]; 
        for(int i=0;i<e.size();++i){
            if(e[i]>=0){
                adj[i].push_back(e[i]);
            }    
        }
        vector<int>visit(n,0);
        vector<int>path(n,0);
        int ans=-1;
        for(int i=0;i<n;++i){
            if(visit[i]==0)
              dfs(adj,i,visit,ans,1,path);
        }
        return ans;
    }
};