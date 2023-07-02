class Solution {
private:
    int f(int i, int n, vector<vector<int>>& a, int ct, vector<int> &t){
        if(i >= n){
            int x = 0;
            for(auto &e : t) if(e) return 0;
            return ct;
        }
        int ans1 = f(i + 1, n, a, ct, t);
        --t[a[i][0]];
        ++t[a[i][1]];
        int ans2 = f(i + 1, n, a, ct + 1, t);
        ++t[a[i][0]];
        --t[a[i][1]];
        return max(ans1, ans2);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& a) {
        vector<int> t(n, 0);
        return f(0, a.size(), a, 0, t);
    }
};