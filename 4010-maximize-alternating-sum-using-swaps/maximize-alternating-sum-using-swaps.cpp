class Solution {
public:
struct DSU {
	vector<int> e; DSU(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};
    long long maxAlternatingSum(vector<int>& a, vector<vector<int>>& swaps) {
        int n = (int)a.size();
        DSU d(n);
        for(auto &x : swaps) {
            d.unite(x[0],x[1]);
        }
        vector<vector<pair<int,int>>>b(n);
        for(int i = 0 ; i < n ; i++) {
            b[d.get(i)].push_back({a[i],i});
        }
        long long ans = 0;
        for(int i = 0 ; i < n ; i++) {
            sort(b[i].begin(),b[i].end());
            int l = 0;
            int r = (int)b[i].size()-1;
            int o = 0;
            int e = 0;
            for(auto &u : b[i]) {
                if(u.second%2) o++;
                else e++;
            }
            while(o--) {
                ans -= b[i][l].first;
                l++;
            }
            while(e--) {
                ans += b[i][l].first;
                l++;
            }
        }
        return ans;
    }
};