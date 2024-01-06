class Solution {
public:
    vector<int> dp;
    int solve(vector<pair<int, pair<int, int>>> &v, vector<int>& s, int i, int prev){
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int t=0, nt=0;
        int ind=lower_bound(s.begin(), s.end(), v[i].second.first)-s.begin();
        t=v[i].second.second+solve(v, s, ind, prev);
        nt=solve(v, s, i+1, prev);
        return dp[i]=max(t, nt);
    }

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<pair<int, pair<int, int>>> v;
        int n=s.size();
        dp.resize(n,  -1);
        for(int i=0; i<n; i++){
            v.push_back({s[i], {e[i], p[i]}});
        }
        sort(s.begin(), s.end());
        sort(v.begin(), v.end());
        return solve(v, s, 0, -1);
    }
};