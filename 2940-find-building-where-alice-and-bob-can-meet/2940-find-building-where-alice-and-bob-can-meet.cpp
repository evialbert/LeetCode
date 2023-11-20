class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<int> ans(m);
        
        vector<int> nge(n);
        stack<int> stk;
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and heights[stk.top()] <= heights[i]) stk.pop();
            if(stk.empty()) nge[i] = n;
            else nge[i] = stk.top();
            stk.push(i);
        }
        
        map<pair<int, int>, int> dp;
        
        auto rec = [&](int curi, int tar, auto &&rec)->int{
            if(curi == n) return -1;
            
            if(dp.find({curi, tar}) != dp.end()) return dp[{curi, tar}];
            if(curi == tar) return curi;
            if(curi > tar and heights[curi] > heights[tar]) return dp[{curi, tar}] = curi;
            return dp[{curi, tar}] = rec(nge[curi], tar, rec);
        };
            
        for(int i = 0; i<m; i++){
            int a = queries[i][0], b = queries[i][1];
            if(a > b) swap(a, b);
            int a1 = rec(b, a, rec);
            ans[i] = a1;
        }
        
        return ans;
    }
};