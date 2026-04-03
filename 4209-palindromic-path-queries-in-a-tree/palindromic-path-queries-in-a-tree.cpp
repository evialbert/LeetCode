class Solution {
public:
    // lca plus euler traversal and updates in a fenwick tree  tree is what needed here.''

    pair<string, string> parse(string s, int i) {
        string z = "";
        while(s[i] != ' ') {
            z += s[i];
            i ++;
        }
        
        string y = "";
        i ++;
        while(i < s.length()) {
            y += s[i];
            i ++;
        }

        return {z, y};
    }


    int get_lca(vector<vector<int>>& par, vector<int> & level, int u, int v) {
        if(level[u] > level[v]) {
            swap(u, v);
        }

        // v is below u.
        int diff = level[v] - level[u];
        
        for(int i = 0; i < 20; i ++) {
            if(diff & (1 << i)) {
                v = par[v][i];
            }
        }

        for(int i = 19; i >= 0; i --) {
            if(v == u) return u;

            if(par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }

       return par[v][0];
    }

    void dfs(vector<int> * adj, 
             vector<vector<int>> & par, 
             vector<int> & euler, 
             vector<int> & level,
             int u, 
             int p,
             int l) {
        par[u][0] = p;
        euler.push_back(u);
        level[u] = l;
        
        for(auto v: adj[u]) {
            if(v != p) {
                dfs(adj, par, euler, level, v, u, l + 1);
            }
        }
        
        euler.push_back(u);
    }

    void update(vector<int> & bit, int index, int val, int N) {
        while(index < N) {
            bit[index] ^= val;
            index += index & (-index);
        }
    }

    int query(vector<int> & bit, int index) {
        int xore = 0;
        while(index > 0) {
            xore ^= bit[index];
            index -= index & (- index);
        }
        return xore;
    }

    int xor_(vector<int> &bit, int l, int r) {
        return query(bit, r + 1) ^ query(bit, l);
    }

    int get_xor(vector<vector<int>> & par, vector<int> & level, vector<int> & bit, string &s, vector<int> *entry_exit, int u, int v) {
        // entry to entry

        int lca = get_lca(par, level, u, v);
        int point_val = 1 << (s[lca] - 'a');

        int s0 = entry_exit[lca][0];
        int e1 = entry_exit[u][0];
        int e2 = entry_exit[v][0];

        int xor1 = xor_(bit, s0, e1);
        int xor2 = xor_(bit, s0, e2);
 
        return point_val ^ xor1 ^ xor2 ;
    }

    
    
    
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<int> adj[n];
        vector<vector<int>> par(n, vector<int>(20, -1));
        vector<int> euler;
        vector<int> level(n);

        int N = 2 * n + 1;

        vector<int> bit(N);

        
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(adj, par, euler, level, 0, -1, 0);
        vector<int> entry_exit[n];
        
        for(int i = 1; i <= 20; i ++) {
            for(int j = 0; j < n; j ++) {
                if(par[j][i - 1] != -1) {
                    par[j][i] = par[par[j][i - 1]][i - 1];
                }
            }
        }

        for(int i = 0; i < euler.size(); i ++) {
            entry_exit[euler[i]].push_back(i);
            int val = s[euler[i]] - 'a';
            update(bit, i + 1, (1 << val), N);
        }


        vector<bool> answer;

        for(auto &it: queries) {
            if(it[0] == 'q') {
                auto p = parse(it, 6);
                int u = stoi(p.first);
                int v = stoi(p.second);

                int xore = get_xor(par, level, bit, s, entry_exit, u, v);
                answer.push_back(__builtin_popcount(xore) <= 1);

            } else {
                
                auto p = parse(it, 7);
                int ind = stoi(p.first);
                int val = 1 << (p.second[0] - 'a');

                int diff = val ^ (1 << (s[ind] - 'a'));
                s[ind] = p.second[0];

                update(bit, entry_exit[ind][0] + 1, diff, N);
                update(bit, entry_exit[ind][1] + 1, diff, N);

            }
        }

        return answer;
    }
};