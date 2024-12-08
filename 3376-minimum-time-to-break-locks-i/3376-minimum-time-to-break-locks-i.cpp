class Solution {
public:
    map<pair<int,int>,int> umap;
    int f(vector<int>& s, int mask, int x, int k) {
        int n = s.size();
        if(mask == (1<<n)-1) {
            return 0;
        }
        
        if(umap.count({mask,x}))
            return umap[{mask,x}];
        int sum = x, add = 0,ans=INT_MAX;
        for(int i=0; i<n; i++) {
            if(mask & (1<<i)) continue;
            add = (s[i] + x - 1)/x;
            ans=min(ans,add+f(s, mask | (1<<i), x + k, k));
        }
        
        return umap[{mask,x}]=ans;
    }
    int findMinimumTime(vector<int>& strength, int K) {
        sort(strength.begin(), strength.end());
        int ans=f(strength, 0, 1, K);
        return ans;
    }
};