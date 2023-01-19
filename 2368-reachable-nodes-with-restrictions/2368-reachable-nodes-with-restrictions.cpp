class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        
        vector<int>adj[n+1];
        vector<bool>vis(n+1,1);
        
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        stack<int>st;
        st.push(0);
        
        for(auto &x:rest){
            vis[x]=0;
        }
        
        long long cnt=0;
        
        while(!st.empty()){
            
            auto k=st.top();
            st.pop();
            
            cnt++;
            vis[k]=0;
            
            for(auto &x:adj[k]){
                if(vis[x]){
                    st.push(x);
                    vis[x]=0;
                }
            }
            
        }
        
        return cnt;
        
    }
};