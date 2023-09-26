class Solution {
public:
    bool prime[100001];
    int v[100001] = {0};
    vector<int> touched;
    
    long dfs(int node,vector<vector<int>>& g){
        if(prime[node] || v[node]++){
            if(prime[node])
                touched.push_back(node);
            return 0;
        }
        int res = 1;
        for(int i : g[node]){
            res += dfs(i,g);
        }
        return res;
    }
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        long res = 0;
        vector<vector<int>> g(n + 1);
        for(auto e : edges){
            g[e[1]].push_back(e[0]);
            g[e[0]].push_back(e[1]);
        }
        memset(prime,1,sizeof(prime));
        prime[1] = 0;
        for(int i = 2;i<=n;i++){
            if(prime[i])
                for(int j = 2;j*i <=n;j++) prime[j*i] = 0;
        }
        vector<long> groups(n+1,1);
        for(int i = 1;i<=n;i++){
            if(!prime[i] && !v[i]){
                touched.clear();
                int a = dfs(i,g);
                for(int j : touched){
                    res += a * groups[j];
                    groups[j] = groups[j] + a;
                }
            }
        }
        return res;
    }
};