class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long>ans(n);
        for(int i = 0; i < n; i++)  ans[edges[i]]+=i;
        return max_element(ans.begin(),ans.end())-ans.begin();
    }
};