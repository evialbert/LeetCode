class Solution {
public:

    void dfs(int child, int parent, int &size, bool &flag, vector<bool> &vis, vector<vector<int>> &graph) {
        vis[child]=true;
        size++; 

        for(auto &nb: graph[child]) {
            if(nb != parent) {
                if(vis[nb]) {
                    flag = true; 
                    return ;
                } else {
                    dfs(nb, child, size, flag, vis, graph);
                }
            }
        }
    } 
    #define ll long long 
    ll maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1);
        for(auto &edge: edges) {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);  
        }   
        ll res = 0;
        vector<bool> vis(n+1, false); 
        int st = 1, end = n; 
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int sz = 0;
            bool flag = false; 
            dfs(i, -1, sz, flag, vis, graph); 
            vector<int> v(sz); 
            if(flag) {
                int s = end - sz + 1; 
                int e = end; 
                end = s-1;
                
                int j = 0, k = sz-1;

                while(j < k) {
                    v[j++] = s++;
                    v[k--] = s++; 
                }
                if(j == k) {
                    v[k] = s; 
                }

                for(int j = 0; j < sz-1; j++) {
                    ll a = (ll)v[j];
                    ll b = (ll)v[j+1];

                    res += (a*b); 
                }
                ll a = (ll)v[0];
                ll b = (ll)v[sz-1];
                res += (a*b);
            } 
        }

        for(int i = 0; i <= n; i++) vis[i] = false;
        vector<int> temp; 
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int sz = 0;
            bool flag = false; 
            dfs(i, -1, sz, flag, vis, graph); 
            vector<int> v(sz); 
            if(!flag && (sz > 1)) {
                temp.push_back(sz); 
            } 
        }
        sort(temp.begin(), temp.end());

        for(int i = temp.size()-1; i >= 0; i--) {
            int sz = temp[i];
            vector<int> v(sz);

            int s = end - sz + 1; 
            int e = end; 
            end = s-1;
            
            int j = 0, k = sz-1;

            while(j < k) {
                v[j++] = s++;
                v[k--] = s++; 
            }
            if(j == k) {
                v[k] = s; 
            }

            for(int j = 0; j < sz-1; j++) {
                ll a = (ll)v[j];
                ll b = (ll)v[j+1];

                res += (a*b); 
            }
        }
        return res;
    }
};