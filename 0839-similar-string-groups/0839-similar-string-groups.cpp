class Solution {
    vector<vector<int> > vec;
    unordered_map<int,unordered_set<int> > mp;
    vector<int> vis;
public:
    bool comp(string &a,string &b){
        int n=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] && (++n)>2){
                return false;
            }
        }
        return true;
    }
    void dfs(int u){
        vis[u]=1;
        for(auto v:mp[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }
    int numSimilarGroups(vector<string>& A) {
        int n=A.size();
        vis.resize(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    if(comp(A[i],A[j])){
                        mp[i].insert(j);
                        mp[j].insert(i);
                    }
                }
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};