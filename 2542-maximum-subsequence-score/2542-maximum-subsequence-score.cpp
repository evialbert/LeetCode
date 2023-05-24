class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) 
    {
        vector<pair<int,int>> vp;
        for (int i = 0; i < b.size(); i++) {
            vp.push_back({b[i], a[i]});
        }
        sort(vp.rbegin(), vp.rend());
        priority_queue<int,vector<int>, greater<int>> pq;
        long long sm = 0, ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            sm += vp[i].second;
            pq.push(vp[i].second);
            if (pq.size() == k)
            {
                ans = max(ans, sm*vp[i].first);
                sm -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};