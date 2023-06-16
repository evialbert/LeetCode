class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<vector<int>> vp;
        int n = queries.size();
        for(int i = 0; i < n; i++)
            vp.push_back({queries[i][0], queries[i][1], i});
        
        sort(vp.begin(), vp.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        priority_queue<vector<int>> p,q;
        for(int i = 0; i < nums1.size(); i++) 
            p.push({nums1[i] + nums2[i], nums1[i], nums2[i]});

        vector<int> ans(n, -1);
        for(auto v: vp) {
            while(!p.empty()) {
                if(p.top()[1] < v[0])
                    p.pop();
                // first is greater and second is smaller then keep it save in next queue because it can be use further
                else if(p.top()[2] < v[1]) 
                    q.push(p.top()), p.pop();
                else 
                    break;
            }

            if(!p.empty())
                ans[v[2]] = p.top()[0];
            
            while(!q.empty()) 
                p.push(q.top()), q.pop();
        }

        return ans;
    }
};