class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        vector<priority_queue<int>> p(m);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                p[i].push(v[i][j]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int res = 0;
            for(int j = 0; j < m; j++){
                res = max(res, p[j].top());
                p[j].pop();
            }
            ans += res;
        }
        
        return ans;
    }
};