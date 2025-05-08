class SegTree {
public:
    int N;
    vector<int> t;
    SegTree() {}
    SegTree(int n): N(n), t(n<<1) {}
    int f(int a, int b) { return a + b; }
    void update(int pos, int val) {
        for (t[pos += N] = val; pos /= 2; )
            t[pos] = f(t[pos * 2], t[pos * 2 + 1]);
    }
    int query(int l, int r) {
        int ra = 0, rb = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l % 2) ra = f(ra, t[l++]);
            if (r % 2) rb = f(rb, t[--r]);
        }
        return f(ra, rb);
    }
};

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        euler.clear();
        adj.clear();
        first_oc.clear();
        last_oc.clear();

        adj.resize(n + 1);
        first_oc.resize(n + 1);
        last_oc.resize(n + 1);
        st = SegTree(2 * n + 2 * edges.size());
        
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }

        dfs(1);
        
        vector<int> ans;
        
        for (auto q : queries) {
            int type = q[0];
            if (type == 1) {
                int u = q[1], v = q[2], ww = q[3];
                if (first_oc[u] > first_oc[v]) swap(u, v);
                st.update(first_oc[v], ww);
                st.update(last_oc[v] + 1, -ww);
            } else {
                int x = q[1];
                ans.push_back(st.query(0, first_oc[x] + 1));
            }
        }
        
        return ans;
    }
    
private:
    vector<vector<pair<int, int>>> adj;
    vector<int> euler, first_oc, last_oc;
    SegTree st;
    
    void dfs(int v, int p = -1, int w = 0) {
        euler.push_back(v);

        first_oc[v] = euler.size() - 1;
        last_oc[v] = euler.size() - 1;
        st.update(euler.size() - 1, w);

        for (auto nei : adj[v]) {
            if (nei.first != p) {
                dfs(nei.first, v, nei.second);

                euler.push_back(v);
                st.update(euler.size() - 1, -nei.second);
                last_oc[v] = euler.size() - 1;
            }
        }
    }
};